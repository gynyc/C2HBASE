/*
 * HTable.h
 *
 *  Created on: 2019年9月6日
 *      Author: apple
 */

#ifndef HTABLE_H_
#define HTABLE_H_
#include <Poco/Dynamic/Var.h>
#include <Poco/Exception.h>
#include "Put.h"
#include "HTableInterface.h"
#include "RegionLocator.h"
#include <iostream>

using namespace std;
//using Poco::Dynamic::List;
using Poco::IOException;







class HTable : public HTableInterface, public RegionLocator
{
	protected:
		//BufferedMutatorImpl *mutator;
	private:
		bool autoFlush = true;
	public:
		 void put(std::list<Put *> &puts) throw(IOException) override;

};



#endif /* HTABLE_H_ */
