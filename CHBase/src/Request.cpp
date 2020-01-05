/*
 * Request.cpp
 *
 *  Created on: 2020年1月2日
 *      Author: stephen
 */

#include "Request.h"
#include <pwd.h>

#define  REQ_SEND_SUCCESS 1
#define  REQ_SEND_FAIL 2
#define  REQ_RECEIVE_FAIL 4
#define  REQ_RECEIVE_SERV_EXCEPTION 8
#define  REQ_RECEIVE_CALLID 16
#define  REQ_RECEIVE_SUCCESS 32

namespace CHBase {

Request::Request() {
	m_socket=new StreamSocket();
}

Request::Request(char* host)
{
	hostname=host;
	m_socket=new StreamSocket();
}

Request::Request(const string& host)
{
	hostname=host;
	m_socket=new StreamSocket();
	connect();
}
void Request::connect()
{
	char buffer[256];
	char* p=buffer;
	int message_len, id_length;
	struct passwd* pwd=getpwuid(getuid());
	SocketAddress SA(hostname);
	ConnectionHeader* pCH=new ConnectionHeader();
	UserInformation* user_Info=new  UserInformation();
	if(pwd!=NULL)
	{
		user_Info->set_effective_user(pwd->pw_name);
	}

	pCH->set_allocated_user_info(user_Info);
	/*here name can be others ?*/
	pCH->set_service_name("ClientSerive");
	id_length=pCH->ByteSize();
	pCH->SerializeWithCachedSizesToArray((uint8*)(buffer+10));

	message_len=id_length+10;
	strcpy(buffer,"HBas");
	buffer[5]='\x50';
	p=&buffer[6];
	id_length=ByteOrder::toNetwork(id_length);
	*((int*)p)=id_length;

	try{
		m_socket->connect(SA);
		Timespan timer(1000);
		m_socket->setSendTimeout(timer);
		m_socket->sendBytes(buffer,message_len);
		state=1;
	}
	catch(Exception& e)
	{
		//printf("%d:receive catch Exception:%s\n",__LINE__,e.message().c_str());
		cout<<__LINE__<<" :receive catch Exception: "<<e.message()<<endl;
		state=1;
	}
}
void Request::reconnect()
{
	m_socket->close();
	connect();
}
Request::~Request() {
	delete m_socket;
}

int Request::call(string& method_name,Message* req_message,Message* res_message)
{
	int sflag=0;
	int rflag=0;
	if(!state)
	{
		reconnect();
	}
	if(state)
	{
		sflag=send(method_name,req_message);
		if(sflag)
		{
			rflag=receive(res_message);
		}
	}
	return (sflag | rflag);

}
int Request::send(string& method_name,Message* req_message)
{
	char* pSendBody=NULL;
	char* p=NULL;
	unsigned char header_size;
	char varint[16];
	int req_size,total_size;

	int req_size_len;
	int message_len;
	int send_len=0;//send data return length ,it must be equal message_len

	RequestHeader* pRH=new  RequestHeader();
	callid=rand();
	pRH->set_call_id(callid);
	pRH->set_method_name(method_name);
	pRH->set_request_param(1);
	header_size=pRH->ByteSize();
	req_size=req_message->ByteSize();
	req_size_len=encode_varint(varint,req_size);
	total_size=sizeof(char)+header_size+req_size_len+req_size;
	message_len=total_size+sizeof(int);
	p=pSendBody=new char[message_len];
	/*
	 * messagelen
	 * total_size_bytes +header_size_byte+header_bytes+req_size_bytes+req_bytes
	 * --4[sizeof(int)]--1[sizeof(char)]------x------------n---------y-----
	 * */
	*((int*)p)=ByteOrder::toNetwork(total_size);
	p+=sizeof(int);
	*p=header_size;
	p++;
	pRH->SerializeWithCachedSizesToArray((uint8*)p);
	p+=header_size;
	encode_varint(p,req_size);
	p+=req_size_len;
	req_message->SerializeWithCachedSizesToArray((uint8*)p);

	try
	{
		send_len=m_socket->sendBytes(pSendBody,message_len);
	}
	catch(Exception& e)
	{
		cout<<__LINE__<<" :receive catch Exception: "<<e.message()<<":error code: "<<e.code()<<endl;
		state=0;
	}
	delete pSendBody;
	delete pRH;
	return (send_len==message_len)?REQ_SEND_SUCCESS:REQ_SEND_FAIL;

}
int Request::receive(Message* res_message)
{
	char buffer[16], *pReceiveBody, *p;
	int total_size;
	uint64_t head_size;
	uint64_t req_size;

	int head_size_len;
	int req_size_len;
	int receive_len=0;
	int ret_code=0;

	ResponseHeader* pRH=new ResponseHeader();

	try
	{
		receive_len=m_socket->receiveBytes(buffer,4);
	}
	catch(Exception& e)
	{
		cout<<__LINE__<<" :receive catch Exception: "<<e.message()<<":error code: "<<e.code()<<endl;
		state=0;
	}
	if(receive_len!=4)
	{
		ret_code|=REQ_RECEIVE_FAIL;
		return ret_code;
	}

	total_size=*((int*)buffer);
	total_size=ByteOrder::fromNetwork(total_size);
	if(total_size==0)
	{
		ret_code|=REQ_RECEIVE_FAIL;
		return ret_code;
	}
	pReceiveBody=new char[total_size];

	try
	{
		receive_len=m_socket->receiveBytes(pReceiveBody,total_size);
	}
	catch(Exception& e)
	{
		cout<<__LINE__<<" :receive catch Exception: "<<e.message()<<":error code: "<<e.code()<<endl;
		state=0;
	}
	if(total_size!=receive_len)
	{
		ret_code|=REQ_RECEIVE_FAIL;
		return ret_code;
	}
	p=pReceiveBody;
	head_size_len=decode_varint(p,&head_size);
	p+=head_size_len;

	if(pRH->ParseFromArray(p,head_size))
	{
		if(pRH->has_exception())
		{
			ret_code|=REQ_RECEIVE_SERV_EXCEPTION;
			const ExceptionResponse& eres=pRH->exception();
			if(eres.has_exception_class_name())
			{
				cout<<"exception_class_name: "<<eres.exception_class_name()<<endl;
			}
			if(eres.has_stack_trace())
			{
				cout<<"stack_trace: "<<eres.stack_trace()<<endl;
			}
			if(eres.has_do_not_retry())
			{
				cout<<"do_not_retry: "<<eres.do_not_retry()<<endl;
			}
			if(eres.has_hostname())
			{
				cout<<"hostname: "<<eres.hostname()<<endl;
			}
			if(eres.has_port())
			{
				cout<<"port: "<<eres.port()<<endl;
			}
		}
		if(pRH->has_call_id())
		{
			if(callid!=pRH->call_id())
			{
				cout<<__FILE__<<" : "<<__LINE__<<" : "<<callid<<" :: "<<pRH->call_id()<<endl;
				ret_code|=REQ_RECEIVE_CALLID;
			}
		}
	}

	if(total_size > (int) head_size+head_size_len)
	{
		p+=head_size;
		req_size_len=decode_varint(p,&req_size);
		p+=req_size_len;
		if(req_size>0)
		{
			res_message->ParseFromArray(p,req_size);
		}
	}
	delete pReceiveBody;
	delete pRH;

	return ret_code|REQ_RECEIVE_SUCCESS;


}


} /* namespace CHBase */
