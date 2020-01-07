/*
 * HTable.h
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#ifndef HTABLE_H_
#define HTABLE_H_
#include <string>
#include "Request.h"

namespace CHBase {

class HTable {
public:
	HTable();
	HTable(string& tableName, Request* pMetaServer);
	virtual ~HTable();
};

} /* namespace CHBase */

#endif /* HTABLE_H_ */
