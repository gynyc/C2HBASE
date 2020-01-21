/*
 * HTable.h
 *
 *  Created on: 2020年1月7日
 *      Author: stephen
 */

#ifndef HTABLE_H_
#define HTABLE_H_
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <future>

#include <list>
#include <set>
#include <map>

#include <Poco/Exception.h>


#include <CHBaseProto/HBase.pb.h>
#include <CHBaseProto/Client.pb.h>
#include <CHBaseProto/MultiRowMutation.pb.h>


#include "Request.h"
#include "Row.h"
#include "Put.h"
#include "HRegionLocator.h"


using namespace std;
//using namespace google::protobuf;
using namespace hbase::pb;
namespace CHBase {

class HTable {
protected:
	int puNum=1000;
	int putSize=200*1024;
private:
	HRegionLocator* locator;
	//bool autoFlush=true;
	string tableName;
public:
	HTable();
	HTable(string& tableName);
	HTable(string& tableName, Request* pMetaServer);
	virtual ~HTable();
	void put(Put* put) throw(IOException) ;
	void put(list<Put*>& puts) throw(IOException);
	void Asyncput(list<Put*>& puts) throw(IOException) ;
	void Asyncput(Put* put) throw(IOException) ;

	void Syncput(list<Put*>& puts) throw(IOException);
	void Syncput(Put* put) throw(IOException) ;
	void Syncput(istream* input, int size) throw(IOException) ;
	void syncPut2RS(set<string>* ss, map<string,list<Put*> >* rg_puts) ;
	int   syncPut2Region(const string& regionName, list<Put*>& puts) throw(IOException);

	int scan(list<Row*>& rows, Request* request) throw(IOException) ;
	int metascan(list<Row*>& rows, Request* request) throw(IOException) ;
};
void syncPutA(HTable* ptable, void* pss, void* prg_puts);

} /* namespace CHBase */

#endif /* HTABLE_H_ */
