/*
 * Connection.cpp
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#include "Connection.h"

namespace CHBase {

Connection::Connection() {


}
Connection::Connection(const char* zkhost)
{
	char host[128];
	this->m_zkhost = zkhost;
	pZK = new ZkClient(zkhost);
	memset(host, 0, sizeof(host));
	pZK->getMaster(host);
	pMaster = new Request(host);
	memset(host, 0, sizeof(host));
	pZK->getMetaRegionServer(host);
	pMetaServer = new Request(host);

}

Connection::~Connection() {
	map<string, HTable* >::iterator mit;
	for(mit=tablemap.begin();mit!=tablemap.end();mit++)
	{
		delete mit->second;
	}
    delete pMetaServer;
    delete pMaster;
    delete pZK;

}
HTable* Connection::getTable(string& tableName)
{
	map<string, HTable* >::iterator mit;
	mit=tablemap.find(tableName);
	if(mit != tablemap.end())
	{
		return mit->second;
	}
	HTable* pTable = new HTable(tableName, pMetaServer);
	tablemap.insert(make_pair(tableName, pTable));
	return pTable;

}
HTable* Connection::getTable(const char* tableName)
{
	string s_tableName=tableName;
	return getTable(s_tableName);
}

} /* namespace CHBase */
