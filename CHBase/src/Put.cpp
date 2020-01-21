/*
 * Put.cpp
 *
 *  Created on: 2020年1月19日
 *      Author: apple
 */

#include "Put.h"

namespace CHBase {

Put::Put() {

}
Put::Put(string& row, long ts) {
	setRow(row);
	this->ts=ts;
}
Put::Put(const char*  row, long ts) {
	string row0=row;
	setRow(row0);
	this->ts=ts;
}
Put::Put(const char*  row, int rowOffset, int rowLength,  long ts) {
	char* p=new char[rowLength+1];
	strncpy(p, row+rowOffset, rowLength);
	string row0=p;

	setRow(row0);
	this->ts=ts;
	delete[] p;
}


Put::~Put() {

}

} /* namespace CHBase */
