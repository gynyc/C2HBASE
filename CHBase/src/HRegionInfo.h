/*
 * HRegionInfo.h
 *
 *  Created on: 2020年1月17日
 *      Author: apple
 */

#ifndef HREGIONINFO_H_
#define HREGIONINFO_H_
#include <string>

using namespace std;

namespace CHBase {

class HRegionInfo {
protected:
	string 	tableName;
	string		regionName;
	long   	regionId;
	int 		replicaId;
	string		startkey;
	string 	endkey;
	bool		offline=false;
	bool		split=false;

public:
	HRegionInfo();
	virtual ~HRegionInfo();

	const string& getEndkey() const {
		return endkey;
	}

	void setEndkey(const string &endkey) {
		this->endkey = endkey;
	}

	bool isOffline() const {
		return offline;
	}

	void setOffline(bool offline = false) {
		this->offline = offline;
	}

	long getRegionId() const {
		return regionId;
	}

	void setRegionId(long regionId) {
		this->regionId = regionId;
	}

	const string& getRegionName() const {
		return regionName;
	}

	void setRegionName(const string& regionName) {
		this->regionName = regionName;
	}

	int getReplicaId() const {
		return replicaId;
	}

	void setReplicaId(int replicaId) {
		this->replicaId = replicaId;
	}

	bool isSplit() const {
		return split;
	}

	void setSplit(bool split = false) {
		this->split = split;
	}

	const string& getStartkey() const {
		return startkey;
	}

	void setStartkey(const string &startkey) {
		this->startkey = startkey;
	}

	const string& getTableName() const {
		return tableName;
	}

	void setTableName(const string &tableName) {
		this->tableName = tableName;
	}
};

} /* namespace CHBase */

#endif /* HREGIONINFO_H_ */
