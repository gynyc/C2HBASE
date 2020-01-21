/*
 * Row.h
 *
 *  Created on: 2020年1月19日
 *      Author: apple
 */

#ifndef ROW_H_
#define ROW_H_
#include <string>
#include <list>
#include <map>
#include <CHBaseProto/Client.pb.h>
#include "Cell.h"


using namespace std;
//using namespace google::protobuf;
using namespace hbase::pb;
namespace CHBase {

class Row {
//private:
protected:
	string row;
	map<string, list<Cell*> > familyMap;
public:
	Row();
	Row(string& row);
	virtual ~Row();
	void row2CV(MutationProto* pmut);
	Row* addColumn(string& family, string& qualifier, string& value);
	void show();
	long heapSize();

	const string& getRow() const {
		return row;
	}

	void setRow(const string &row) {
		this->row = row;
	}
};

} /* namespace CHBase */

#endif /* ROW_H_ */
