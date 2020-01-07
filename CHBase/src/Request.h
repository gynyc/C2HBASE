/*
 * Request.h
 *
 *  Created on: 2020年1月2日
 *      Author: stephen
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <unistd.h>
#include <iostream>
#include <string>
#include <Poco/ByteOrder.h>
#include <Poco/net/StreamSocket.h>
#include <Poco/net/SocketAddress.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <CHBaseProto/RPC.pb.h>


using namespace std;
using namespace google::protobuf;
using namespace hbase::pb;
using namespace Poco;
using namespace Poco::Net;
//using Poco::Net::StreamSocket;
//using Poco::Net::SocketAddress;
//using Poco::Net::SocketAddress;
//using hbase::pb::ConnectionHeader;

enum REQUEST_ERRORS {
	REQ_SEND_FAIL = 0,
	REQ_SEND_SUCCESS = 1,
	REQ_RECEIVE_FAIL = 2,
	REQ_RECEIVE_CALLID = 4,
	REQ_RECEIVE_SERV_EXCEPTION = 8,
	REQ_RECEIVE_SUCCESS = 16
};
namespace CHBase {

class Request {
public:
	Request();
	Request(char* host);
	Request(const string& host);
	void connect();
	void reconnect();
	int call(string& method_name,Message* req_message,Message* res_message);
	int send(string& method_name,Message* req_message);
	int receive(Message* res_message);

	virtual ~Request();
public:
	inline int encode_varint(char* buf,uint64_t x)
	{
			int n;
			n = 0;
			while (x > 127)
			{
					buf[n++] = (char) (0x80 | (x & 0x7F));
					x >>= 7;
			}
			buf[n++] = (char) x;
			return n;
	}
	inline int decode_varint(char* buf,uint64_t* y)
	{

			int shift, n;
			uint64_t x, c;
			n = 0;
			x = 0;
			for (shift = 0; shift < 64; shift += 7)
			{
				c = (uint64_t) buf[n++];
				x |= (c & 0x7F) << shift;
				if ((c & 0x80) == 0)
				{
					break;
				}
			}
			*y=x;
			return n;
	}
private:
	int state;
	StreamSocket* m_socket;
	string hostname;
public:
	unsigned int callid;
};

} /* namespace CHBase */

#endif /* REQUEST_H_ */
