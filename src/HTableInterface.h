/*
 * HTableInterface.h
 *
 *  Created on: 2019年9月7日
 *      Author: apple
 */

#ifndef HTABLEINTERFACE_H_
#define HTABLEINTERFACE_H_
#include "Table.h"

class HTableInterface :public Table
{
public:
	HTableInterface();
	virtual ~HTableInterface();
};

#endif /* HTABLEINTERFACE_H_ */
