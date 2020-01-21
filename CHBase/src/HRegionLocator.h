/*
 * HRegionLocator.h
 *
 *  Created on: 2020年1月17日
 *      Author: apple
 */

#ifndef HREGIONLOCATOR_H_
#define HREGIONLOCATOR_H_
#include <string>
#include <list>
#include <map>

#include <CHBaseProto/Client.pb.h>
#include <CHBaseProto/MultiRowMutation.pb.h>
#include <CHBaseProto/HBase.pb.h>

#include "HRegionInfo.h"
#include "HRegionLocation.h"
#include "Row.h"
#include "Request.h"

using namespace std;
using namespace hbase::pb;


namespace CHBase {

class HRegionLocator {
private:
	string tableName;
	Request* pMetaServer;
	map<string, HRegionLocation*> metaInfo;
	map<string, HRegionLocation*> RegionRows;
	map<string, Request*> reqInfo;


public:
	HRegionLocator();
	HRegionLocator(const string& tableName, Request* pMetaServer);
	virtual ~HRegionLocator();
	const string& getServerName(const string& RegionName);
	Request* getRequest(const string& RegionName);
	const string& getRegionName(const string& row);
	HRegionLocation& getRegionLocation(const string& row);

	void reloadLocation();

	const string& getTableName() const {
		return tableName;
	}

private:
	int metaScan() throw(IOException);
	void transRow2Meta();

};

} /* namespace CHBase */

#endif /* HREGIONLOCATOR_H_ */
