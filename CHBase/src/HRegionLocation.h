/*
 * HRegionLocation.h
 *
 *  Created on: 2020年1月17日
 *      Author: apple
 */

#ifndef HREGIONLOCATION_H_
#define HREGIONLOCATION_H_
#include <string>
#include "HRegionInfo.h"


using namespace std;

namespace CHBase {

class HRegionLocation {
protected:
	HRegionInfo regionInfo;
	string serverName;
	long seqNum;
public:
	HRegionLocation();
	virtual ~HRegionLocation();

	HRegionInfo& getRegionInfo() {
		return regionInfo;
	}

	void setRegionInfo(const HRegionInfo &regionInfo) {
		this->regionInfo = regionInfo;
	}

	long getSeqNum() const {
		return seqNum;
	}

	void setSeqNum(long seqNum) {
		this->seqNum = seqNum;
	}

	const string& getServerName() const {
		return serverName;
	}

	void setServerName(const string &serverName) {
		this->serverName = serverName;
	}
};

} /* namespace CHBase */

#endif /* HREGIONLOCATION_H_ */
