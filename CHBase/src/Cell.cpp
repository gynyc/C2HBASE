/*
 * Cell.cpp
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#include "Cell.h"

namespace CHBase {

Cell::Cell() {

}
Cell::Cell(string& family, string& qualifier, string& RowKey, string& Value, long timestamp) {
	this->RowKey = RowKey;
	this->Value = Value;
	this->family = family;
	this->qualifier = qualifier;
	this->timestamp = timestamp;

}

Cell::~Cell() {

}

} /* namespace CHBase */
