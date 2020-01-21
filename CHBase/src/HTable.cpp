/*
 * HTable.cpp
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#include "HTable.h"

namespace CHBase {

HTable::HTable() {

}
HTable::HTable(string& tableName)
{
	this->tableName=tableName;
	locator=new HRegionLocator();
}
HTable::HTable(string& tableName, Request* pMetaServer)
{
	this->tableName=tableName;
	locator=new HRegionLocator(tableName, pMetaServer);
}
HTable::~HTable() {

}
int HTable::scan(list<Row*>& rows, Request* request) throw(IOException) {
	return 0;
}
int HTable::metascan(list<Row*>& rows, Request* request) throw(IOException) {
	string method_name="Scan";
	string table_name;
	RegionSpecifier* prsf=new RegionSpecifier();
	Column* pcol;
	Scan* psc=new Scan();
	ScanRequest* psreq=new ScanRequest();
	ScanResponse* psrsp=new ScanResponse();
	prsf->set_type(RegionSpecifier_RegionSpecifierType_REGION_NAME);

	string region_name="hbase:meta,,1";
	prsf->set_value(region_name);
	psreq->set_allocated_region(prsf);
	psreq->set_number_of_rows(100);

	pcol=psc->add_column();
	pcol->set_family("info");
	pcol->add_qualifier("regioninfo");
	pcol->add_qualifier("server");

	int n;
	if((n=this->tableName.find("default:"))==string::npos)
	{
		table_name=this->tableName;
	}
	else
	{
		table_name=this->tableName.substr(n+8);
	}

	string startrow=table_name+",";

	psc->set_start_row(startrow);
	string stoprow=startrow+":";
	psc->set_stop_row(stoprow);
	psc->set_max_versions(1);
	psc->set_cache_blocks(true);
	psc->set_max_result_size(2097152);
	psc->set_caching(100);

	psreq->set_allocated_scan(psc);
	request->call(method_name, psreq, psrsp);

	for(int i=0; i<psrsp->results_size(); i++)
	{
		const Result& rst=psrsp->results(1);
		for(int j=0; j<rst.cell_size(); j++)
		{
			const ::hbase::pb::Cell& cel=rst.cell(j);
			if(cel.has_row())
			{
				cout<<"row:"<<cel.row()<<endl;

			}
			if(cel.has_family())
			{
				cout<<"family:"<<cel.family()<<endl;
			}

			if(cel.has_qualifier())
			{
				cout<<"qualifier:"<<cel.qualifier()<<endl;
				if(cel.has_value())
				{

				}
			}

		}
	}

	delete psreq;
	delete psrsp;
	return 0;
}

void syncPutA(HTable* ptable, void* pss, void* prg_puts)
{
	set<string>* ss=(set<string>*)(pss);
	map<string,list<Put*> >* rg_puts=(map<string,list<Put*> >*)(prg_puts);
	ptable->syncPut2RS(ss, rg_puts);
}
void HTable::put(Put* put) throw(IOException) {

}
void HTable::put(list<Put*>& puts) throw(IOException) {

}
void HTable::Asyncput(list<Put*>& puts) throw(IOException) {

}
void HTable::Asyncput(Put* put) throw(IOException) {

}
void HTable::Syncput(list<Put*>& puts) throw(IOException) {
	map<string, list<Put*> >  rg_puts;
	map<string, list<Put*> >::iterator mpit;

	list<Put*>::iterator lpit;

	for(lpit=puts.begin(); lpit!=puts.end(); lpit++)
	{
		const string& RegionName=locator->getRegionName(((Put*)*lpit)->getRow());
		mpit=rg_puts.find(RegionName);
		if(mpit==rg_puts.end())
		{
			list<Put*> lps;
			lps.push_back(*lpit);
			rg_puts.insert(make_pair(RegionName, lps));
		}
		else
		{
			mpit->second.push_back(*lpit);
		}
	}

	map<string, set<string> >  rgs_rg;
	map<string, set<string> >::iterator msit;
	for(mpit=rg_puts.begin(); mpit!=rg_puts.end(); mpit++)
	{
		const string& ServerName=locator->getServerName(mpit->first);
		msit=rgs_rg.find(ServerName);
		if(msit==rgs_rg.end())
		{
			set<string> ss;
			ss.insert(mpit->first);
			rgs_rg.insert(make_pair(ServerName, ss));
		}
		else
		{
			msit->second.insert(mpit->first);
		}
	}

	if(rgs_rg.size()==1)
	{
		msit=rgs_rg.begin();
		syncPut2RS(&(msit->second), &rg_puts);
	}
	else
	{
		unsigned int i=rgs_rg.size();
		std::future<void> result[i];
		for(msit=rgs_rg.begin(); msit!=rgs_rg.end(); msit++)
		{
			HTable* ptable=this;
			void* ss=(void*)(&msit->second);
			void* ps=(void*)(&rg_puts);
			result[i]=std::async(syncPutA, ptable, ss, ps);
			i--;
		}
		for(i=0; i<rgs_rg.size(); i++)
		{
			result[i].get();
		}
	}
}
void HTable::Syncput(Put* put) throw(IOException) {
	string method_name="Mutate";
	MutateRequest* pmreq=new MutateRequest();
	MutateResponse* pmrsp=new MutateResponse();
	RegionSpecifier* prsf=new RegionSpecifier();
	MutationProto* pmut=new MutationProto();

	prsf->set_type(RegionSpecifier_RegionSpecifierType_REGION_NAME);
	const string& regionName=locator->getRegionName(put->getRow());
	prsf->set_value(regionName);

	pmreq->set_allocated_region(prsf);

	pmut->set_row(put->getRow());
	pmut->set_mutate_type(MutationProto_MutationType_PUT);
	put->row2CV(pmut);

	Request* prequest=locator->getRequest(regionName);
	prequest->call(method_name, pmreq, pmrsp);
	delete pmreq;
	delete pmrsp;

}
void HTable::Syncput(istream* input, int size) throw(IOException) {

}
void HTable::syncPut2RS(set<string>* ss, map<string,list<Put*> >* rg_puts) {
	int puts_Count=0;
	long puts_Size=0;
	set<string>::iterator sit;
	map<string, list<Put*> >::iterator mpit;
	list<Put*> puts;
	list<Put*>::iterator lpit;

	for(sit=ss->begin(); sit!=ss->end(); sit++)
	{
		mpit=rg_puts->find(*sit);
		if(mpit!=rg_puts->end())
		{
			for(lpit=mpit->second.begin(); lpit!=mpit->second.end(); lpit++)
			{
				puts_Count++;
				puts_Size+=((Put*)*lpit)->heapSize();
				puts.push_front(((Put*)*lpit));
				if(puts_Count>=this->puNum || puts_Size>this->putSize)
				{
					syncPut2Region(mpit->first, puts);
					puts_Count=0;
					puts_Size=0;
					puts.clear();
				}
			}
			if(puts_Count!=0)
			{
				syncPut2Region(mpit->first, puts);
				puts_Count=0;
				puts_Size=0;
				puts.clear();
			}

		}
	}

}
int HTable::syncPut2Region(const string& regionName, list<Put*>& puts) throw(IOException) {
	int ret_code=0;
	string method_name="Multi";
	MultiRequest* pmreq=new MultiRequest();
	MultiResponse* pmrsp=new MultiResponse();
	RegionSpecifier* prsf=new RegionSpecifier();
	RegionAction* pRA=pmreq->add_regionaction();
	prsf->set_type(RegionSpecifier_RegionSpecifierType_REGION_NAME);
	prsf->set_value(regionName);
	pRA->set_allocated_region(prsf);
	list<Put*>::iterator lpit;
	for(lpit=puts.begin(); lpit!=puts.end(); lpit++)
	{
		Action* pAct=pRA->add_action();
		MutationProto* pmut=new MutationProto();
		pmut->set_row(((Put*)*lpit)->getRow());
		pmut->set_mutate_type(MutationProto_MutationType_PUT);
		((Put*)*lpit)->row2CV(pmut);
		pAct->set_allocated_mutation(pmut);
	}

	Request* prequest=locator->getRequest(regionName);
	ret_code=prequest->call(method_name, pmreq, pmrsp);

	for(int i=0; i<pmrsp->regionactionresult_size(); i++)
	{
		const RegionActionResult& rar=pmrsp->regionactionresult(i);
		if(rar.has_exception())
		{
			const NameBytesPair& nbp=rar.exception();
			cout<<__FILE__<<" : "<<__LINE__<<nbp.name()<<nbp.value()<<endl;
		}
		for(int j=0; j<rar.resultorexception_size(); j++)
		{
			const ResultOrException& roe=rar.resultorexception(j);
			if(roe.has_result())
			{
				const Result& rs=roe.result();
				if(rs.cell_size()>0) cout<<__FILE__<<" : "<<__LINE__<<":cell_size:"<<rs.cell_size()<<endl;
				if(rs.has_associated_cell_count())cout<<__FILE__<<" : "<<__LINE__<<":associated_cell_count:"<<rs.associated_cell_count()<<endl;
				if(rs.has_exists())cout<<__FILE__<<" : "<<__LINE__<<":exits:"<<rs.exists()<<endl;
				if(rs.has_partial())cout<<__FILE__<<" : "<<__LINE__<<":partial:"<<rs.partial()<<endl;
				if(rs.has_stale())cout<<__FILE__<<" : "<<__LINE__<<":stale:"<<rs.stale()<<endl;
			}
			if(roe.has_exception())
			{
				cout<<__FILE__<<" : "<<__LINE__<<": has_exception"<<endl;

			}
		}
	}
	delete pmreq;
	delete pmrsp;
	return ret_code;

}



} /* namespace CHBase */
