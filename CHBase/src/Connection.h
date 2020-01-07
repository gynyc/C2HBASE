/*
 * Connection.h
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <map>
#include <Poco/Thread.h>

#include "ZkClient.h"
#include "Request.h"
#include "HTable.h"

using namespace std;
using namespace Poco;


namespace CHBase {

class Connection {
public:
	Connection();
	Connection(const char* zkhost);
	virtual ~Connection();
	HTable* getTable(string& tableName);
	HTable* getTable(const char* tableName);

	const string& getZkhost() const {
		return m_zkhost;
	}

	void setZkhost(const string &zkhost) {
		m_zkhost = zkhost;
	}

	Request* getMaster() const {
		return pMaster;
	}

	void setMaster(Request *master) {
		pMaster = master;
	}

	Request* getMetaServer() const {
		return pMetaServer;
	}

	void setMetaServer(Request *metaServer) {
		pMetaServer = metaServer;
	}

	ZkClient* getZk() const {
		return pZK;
	}

	void setZk(ZkClient *zk) {
		pZK = zk;
	}

private:
	ZkClient* pZK;
	Request* pMetaServer;
	Request* pMaster;
	map<string, HTable* > tablemap;
	string m_zkhost;

};

} /* namespace CHBase */

#endif /* CONNECTION_H_ */
