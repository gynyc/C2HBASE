/*
 * Row.cpp
 *
 *  Created on: 2020年1月19日
 *      Author: apple
 */

#include "Row.h"

namespace CHBase {

Row::Row() {
}
Row::Row(string& row) {
	this->row=row;
}
Row::~Row() {

}
void Row::row2CV(MutationProto* pmut)
{
	MutationProto_ColumnValue* pCV;
	MutationProto_ColumnValue_QualifierValue* pQV;
	map<string, list<Cell*> >::iterator mcit;
	list<Cell*>::iterator lcit;
	for(mcit=familyMap.begin();mcit!=familyMap.end();mcit++)
	{
		pCV=pmut->add_column_value();
		pCV->set_family(mcit->first);

		for(lcit=mcit->second.begin(); lcit!=mcit->second.end(); lcit++)
		{
			pQV=pCV->add_qualifier_value();
			pQV->set_qualifier(((Cell*)*lcit)->getQualifier());
			pQV->set_value(((Cell*)*lcit)->getValue());
			pQV->set_timestamp(((Cell*)*lcit)->getTimestamp());
		}
	}
}

Row* Row::addColumn(string& family, string& qualifier, string& value)
{
	map<string, list<Cell*> >::iterator mcit;
	list<Cell*>::iterator lcit;
	Cell* cel=new  Cell(family, qualifier, row, value);
	mcit=familyMap.find(family);

	if(mcit==familyMap.end())
	{
		list<Cell*> lc;
		lc.push_back(cel);
		familyMap.insert(make_pair(family,lc));
	}
	else
	{
		mcit->second.push_back(cel);
	}
	return this;
}
void Row::show()
{
	map<string, list<Cell*> >::iterator mcit;
	list<Cell*>::iterator lcit;
	cout<<"rowkey is : "<<row<<endl;

	for(mcit=familyMap.begin();mcit!=familyMap.end();mcit++)
	{
		cout<<"family is : "<<mcit->first<<endl;

		for(lcit=mcit->second.begin();lcit!=mcit->second.end();lcit++)
		{
			((Cell*)*lcit)->show();
		}
	}
}

long Row::heapSize()
{
	map<string, list<Cell*> >::iterator mcit;
	list<Cell*>::iterator lcit;
	long heapsize=0;
	heapsize+=this->row.size();
	for(mcit=familyMap.begin();mcit!=familyMap.end();mcit++)
	{
		heapsize+=mcit->first.size();
		for(lcit=mcit->second.begin();lcit!=mcit->second.end();lcit++)
		{
			heapsize=+((Cell*)*lcit)->size();
		}
	}
	return heapsize;

}

} /* namespace CHBase */
