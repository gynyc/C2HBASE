/*
 * Row.h
 *
 *  Created on: 2019年9月9日
 *      Author: apple
 */

#ifndef ROW_H_
#define ROW_H_
typedef unsigned char BYTE;


class Row {
public:
	Row();
	virtual ~Row();
	virtual  BYTE* getRow()=0;
};

#endif /* ROW_H_ */
