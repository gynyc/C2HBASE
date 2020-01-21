/*
 * HRegionLocator.cpp
 *
 *  Created on: 2020年1月17日
 *      Author: apple
 */

#include "HRegionLocator.h"

namespace CHBase {

HRegionLocator::HRegionLocator() {
	// TODO Auto-generated constructor stub

}
HRegionLocator::HRegionLocator(const string& tableName, Request* pMetaServer) {
	this->tableName=tableName;
	this->pMetaServer=pMetaServer;
	metaScan();
	transRow2Meta();
}
void HRegionLocator::reloadLocation() {
	RegionRows.clear();
	metaScan();
	transRow2Meta();
}
HRegionLocator::~HRegionLocator() {
	map<string, Request*>::iterator mqit;
	for(mqit = reqInfo.begin(); mqit != reqInfo.end(); mqit++)
	{
		delete mqit->second;
	}
}
int HRegionLocator::metaScan() throw(IOException)
{
	map<string, HRegionLocation*>::iterator mlit;
	HRegionLocation* phrl=NULL;

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
	pMetaServer->call(method_name, psreq, psrsp);



	for(int i=0; i<psrsp->results_size(); i++)
	{
		const Result& rst=psrsp->results(1);
		for(int j=0; j<rst.cell_size(); j++)
		{
			const ::hbase::pb::Cell& cel=rst.cell(j);
			if(cel.has_row())
			{
				mlit=RegionRows.find(cel.row());
				if(mlit==RegionRows.end())
				{
					phrl=new HRegionLocation();
					RegionRows.insert(make_pair(cel.row(), phrl));
				}
				else
				{
					phrl=mlit->second;
				}
				//const HRegionInfo& hRegionInfo=phrl->getRegionInfo();
				//hRegionInfo.setRegionName(cel.row());
				phrl->getRegionInfo().setRegionName(cel.row());

			}
			else
			{

			}
			if(cel.has_qualifier())
			{
				if(cel.has_value())
				{
					if(cel.qualifier()=="regioninfo")
					{
						RegionInfo* prif=new RegionInfo();
						const string& strrif=cel.value();
						prif->ParseFromString(strrif.substr(4, strrif.size()-4));
						if(prif->has_region_id())
						{
							phrl->getRegionInfo().setRegionId(prif->region_id());
						}
						if(prif->has_table_name())
						{
							const TableName& tbn=prif->table_name();
							if(tbn.has_qualifier())
							{
								phrl->getRegionInfo().setTableName(tbn.qualifier());
							}
						}
						if(prif->has_start_key())
						{
							phrl->getRegionInfo().setStartkey(prif->start_key());
						}
						if(prif->has_end_key())
						{
							phrl->getRegionInfo().setEndkey(prif->end_key());
						}
						delete prif;
					}
					if(cel.qualifier()=="server")
					{
						phrl->setServerName(cel.value());
					}

				}
			}
		}
	}

	delete psreq;
	delete psrsp;
	return 0;
}
void HRegionLocator::transRow2Meta()
{
	map<string, HRegionLocation*>::iterator mlit;
	map<string, Request*>::iterator mqit;
	metaInfo.clear();
	for(mlit = RegionRows.begin(); mlit != RegionRows.end(); mlit++)
	{
		cout<<__FILE__<<" : "<<__LINE__<<" : "<<mlit->first<<endl;
		metaInfo.insert(make_pair(mlit->second->getRegionInfo().getStartkey(), mlit->second));
		mqit=reqInfo.find(mlit->second->getServerName());
		if(mqit == reqInfo.end())
		{
			Request* req=new Request(mlit->second->getServerName());
			reqInfo.insert(make_pair(mlit->second->getServerName(), req));
			cout<<__FILE__<<" : "<<__LINE__<<" : "<<mlit->second->getServerName()<<endl;
		}
	}
	for(mlit = metaInfo.begin(); mlit != metaInfo.end(); mlit++)
	{
		cout<<__FILE__<<" : "<<__LINE__<<" : "<<mlit->first<<endl;
	}

}
const string& HRegionLocator::getServerName(const string& RegionName)
{
	map<string, HRegionLocation*>::iterator mlit;
	mlit = RegionRows.find(RegionName);
	if(mlit != RegionRows.end())
	{
		return mlit->second->getServerName();
	}
	throw (IOException(RegionName));
}
Request* HRegionLocator::getRequest(const string& RegionName)
{
	map<string, HRegionLocation*>::iterator mlit;
	map<string, Request*>::iterator mqit;
	mlit = RegionRows.find(RegionName);
	if(mlit == RegionRows.end())
	{
		return NULL;
	}
	mqit=reqInfo.find(mlit->second->getServerName());
	if(mqit == reqInfo.end())
	{
		return NULL;
	}
	return mqit->second;
}
const string& HRegionLocator::getRegionName(const string& row)
{
	map<string, HRegionLocation*>::iterator mlit;
	mlit=metaInfo.upper_bound(row);
	mlit--;
	return mlit->second->getRegionInfo().getRegionName();
}
HRegionLocation& HRegionLocator::getRegionLocation(const string& row)
{
	map<string, HRegionLocation*>::iterator mlit;
	mlit=metaInfo.upper_bound(row);
	mlit--;
	return *(mlit->second);
}


} /* namespace CHBase */
