/*
 * ZkClient.h
 *
 *  Created on: 2020年1月5日
 *      Author: stephen
 */

#ifndef ZKCLIENT_H_
#define ZKCLIENT_H_

#include <unistd.h>
#include <iostream>
#include <string>
#include <thread>

#include <Poco/ByteOrder.h>
#include <zookeeper/zookeeper.h>
//#include <zookeeper_log.h>
/*  use zookeeper/ path  is no useful , it cant compile successful ,
 *      for in zookeeper_log.h, it use <zookeeper.h> not <zookeeper/zookeeper.h>
 * so have to be use  include directory,
 *  g++  -I/usr/local/include/zookeeper/
 *
 */
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <CHBaseProto/Zookeeper.pb.h>

using namespace std;
using namespace google::protobuf;
using namespace hbase::pb;
using namespace Poco;


namespace CHBase {

void Init_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx);
class ZkClient {
public:
	ZkClient();
	virtual ~ZkClient();
	ZkClient(const char* host);
	ZkClient(const char* host,const char* path);
	int getMaster(char* qhost);
	int getMetaRegionServer(char* qhost);
private:
	zhandle_t* zkhandle;
};

} /* namespace CHBase */

#endif /* ZKCLIENT_H_ */
