/*
 * Table.h
 *
 *  Created on: 2019年9月8日
 *      Author: apple
 */

#ifndef TABLE_H_
#define TABLE_H_
#include <Poco/Dynamic/Var.h>
#include <Poco/Exception.h>
#include "Put.h"

using namespace std;
//using Poco::Dynamic::List;
using Poco::IOException;

class Table {
public:
	Table();
	virtual void put(std::list<Put*> &puts) throw(IOException) =0;

	virtual ~Table();
};

#endif /* TABLE_H_ */
