/*
 * ZkClient.cpp
 *
 *  Created on: 2020年1月5日
 *      Author: apple
 */

#include "ZkClient.h"

namespace CHBase {

void Init_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
	if(type==ZOO_SESSION_EVENT)
	{
		if(state==ZOO_CONNECTED_STATE)
		{
			cout<<"QueryServer : Connected to zookeeper service successful!"<<endl;
		}
		else if(state==ZOO_EXPIRED_SESSION_STATE)
		{
			cout<<"Zookeeper session expired!"<<endl;
		}
	}
	cout<<"zookeeper client thread is :"<<this_thread::get_id()<<endl;
}
ZkClient::ZkClient() {

}
ZkClient::ZkClient(const char* host)
{
	int timeout=30000;
	char* hello=(char *)"hello zookeeper.";
	zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);
	zkhandle=zookeeper_init(host, Init_watcher_g, timeout, NULL,(void*)hello, 0);
	if(zkhandle==NULL)
	{
		fprintf(stderr,"Error when connecting to zookeeper servers...\n");
	}
	cout<<"zookeeper client's parent thread is :"<<this_thread::get_id()<<endl;
}
int ZkClient::getMaster(char *qhost)
{
	const char* path="/hbase/master";
	char buffer[256];
	int buffer_len=256;
	struct Stat stat;
	Master ms;
	zoo_get(zkhandle, path, 0, buffer, &buffer_len, &stat);
	int data_len=*(int *)(buffer+1);
	data_len=ByteOrder::fromNetwork(data_len);
	ms.ParseFromArray(buffer+9+data_len,buffer_len-9-data_len);
	cout<<" :: buffer len:"<<buffer_len<<"::data len:"<<data_len<<endl;
	if(ms.master().has_host_name())
		cout<<"master hostname : "<<ms.master().host_name()<<endl;
	if(ms.master().has_port())
		cout<<"master port         : "<<ms.master().port()<<endl;

	sprintf(qhost, "%s:%d", ms.master().host_name().c_str(), ms.master().port());
	return 1;
}
int ZkClient::getMetaRegionServer(char *qhost)
{
	const char* path="/hbase/meta-region-server";
	char buffer[256];
	int buffer_len=256;
	struct Stat stat;
	MetaRegionServer mrs;
	zoo_get(zkhandle, path, 0, buffer, &buffer_len, &stat);
	int data_len=*(int *)(buffer+1);
	data_len=ByteOrder::fromNetwork(data_len);
	mrs.ParseFromArray(buffer+9+data_len,buffer_len-9-data_len);
	cout<<" :: buffer len:"<<buffer_len<<"::data len:"<<data_len<<endl;
	if(mrs.server().has_host_name())
		cout<<"master hostname : "<<mrs.server().host_name()<<endl;
	if(mrs.server().has_port())
		cout<<"master port         : "<<mrs.server().port()<<endl;

	sprintf(qhost, "%s:%d", mrs.server().host_name().c_str(), mrs.server().port());
	return 1;
}

ZkClient::~ZkClient() {
	if(zkhandle!=NULL)
		zookeeper_close(zkhandle);
}

} /* namespace CHBase */
