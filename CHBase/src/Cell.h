/*
 * Cell.h
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#ifndef CELL_H_
#define CELL_H_
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace CHBase {

class Cell {
private:
	string RowKey;
	string Value;
	string family;
	string qualifier;
	long timestamp;

public:
	Cell();
	//Cell(string& family, string& qualifier, string& RowKey, string& Value);
	Cell(string& family, string& qualifier, string& RowKey, string& Value, long timestamp=((unsigned long )(-1))>>1);
	virtual ~Cell();

	void show()
	{
		cout<<" qualifier: "<<qualifier<<endl;
		cout<<" Value: "<<Value<<endl;

	}
	int size()
	{
		return RowKey.size() + Value.size() + family.size() + qualifier.size() +sizeof(timestamp);
	}
	const string& getFamily() const {
		return family;
	}

	void setFamily(const string &family) {
		this->family = family;
	}

	const string& getQualifier() const {
		return qualifier;
	}

	void setQualifier(const string &qualifier) {
		this->qualifier = qualifier;
	}

	const string& getRowKey() const {
		return RowKey;
	}

	void setRowKey(const string &rowKey) {
		RowKey = rowKey;
	}

	long getTimestamp() const {
		return timestamp;
	}

	void setTimestamp(long timestamp) {
		this->timestamp = timestamp;
	}

	const string& getValue() const {
		return Value;
	}

	void setValue(const string &value) {
		Value = value;
	}
};

} /* namespace CHBase */

#endif /* CELL_H_ */
