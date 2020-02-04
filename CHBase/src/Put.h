/*
 * Put.h
 *
 *  Created on: 2020年1月19日
 *      Author: apple
 */

#ifndef PUT_H_
#define PUT_H_
#include <string>
#include "Mutation.h"


using namespace std;
namespace CHBase {

class Put : public Mutation{
public:
	Put();
	Put(string& row, long ts=((unsigned long)(-1))>>1);
	Put(const char*  row, long ts=((unsigned long)(-1))>>1);
	Put(const char*  row, int rowOffset, int rowLength,  long ts=((unsigned long)(-1))>>1);
	virtual ~Put();

};

} /* namespace CHBase */

#endif /* PUT_H_ */
