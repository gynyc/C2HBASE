/*
 * Mutation.cpp
 *
 *  Created on: 2020年1月19日
 *      Author: apple
 */

#include "Mutation.h"

namespace CHBase {

Mutation::Mutation() {

}

Mutation::~Mutation() {

}
long Mutation::heapSize()
{

	long heapsize=MUTATION_OVERHEAD;
	heapsize+=Row::heapSize();
	return heapsize;

}

} /* namespace CHBase */
