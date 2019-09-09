/*
 * Mutation.h
 *
 *  Created on: 2019年9月9日
 *      Author: apple
 */

#ifndef MUTATION_H_
#define MUTATION_H_
#include "OperationWithAttributes.h"
#include "Row.h"

class Mutation : public OperationWithAttributes, public Row
{
public:
	Mutation();
	virtual ~Mutation();
};

#endif /* MUTATION_H_ */
