/*
 * PyCHBaseDocStrings.h
 *
 *  Created on: 2020年1月21日
 *      Author: apple
 */

#ifndef PYCHBASEDOCSTRINGS_H_
#define PYCHBASEDOCSTRINGS_H_

const char pyhbase_init_doc[]=
"Init 8 connects, and 8*16=128 Tables\n"
"\n"
;

const char pyhbase_connect_doc[]=
"Return the connect handle which keep socket connect to zookeeper,\n"
"HBase Master, HBase Meta Region Server;\n"
"Meanwhile, it keeps all tables handles in this cluster;\n"
"Parameters:\n"
"host: comma separated host:port pairs, each corresponding to a zk\n"
"  server, e.g. '127.0.0.1:3000, 127.0.0.1:3001, 127.0.0.1:3002'\n"
"\n"
;

const char pyhbase_getTable_doc[]=
"Return  table handle which need to be provisioned\n"
"Parameters:\n"
" TableName: table's name"
"\n"
;

const char pyhbase_Puts_doc[]=
"Execute Put table action, \n"
"Parameters:\n"
" TableID: table's handle,\n"
" put data Dictionary: \n"
"     { {row1, {c1, d1}}, {row2, {c2, d2} } } \n"
"\n"
;


#endif /* PYCHBASEDOCSTRINGS_H_ */
