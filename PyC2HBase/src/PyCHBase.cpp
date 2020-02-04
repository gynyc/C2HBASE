
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

#include <Connection.h>
#include <Cell.h>
#include <HTable.h>
#include <Put.h>

using namespace std;
using namespace CHBase;

PyObject* C2HBaseException=NULL;
PyObject* SystemErrorException;

enum C2HB_ERRORS{
	C2HBOK=0,
	C2HBSYSTEMERROR= 1
};

PyObject* error_to_exception(int errcode)
{
	switch(errcode)
	{
		case C2HBSYSTEMERROR:
			return SystemErrorException;
		case C2HBOK:
		default:
			return NULL;
	}
}


#define CHECK_CONNID(z) if( (z)<0 || (z) >= num_hConns ) {   \
		PyErr_SetString( C2HBaseException, "handle out of range" ); \
		return NULL;  \
} else if ( hConns[ (z) ] == NULL ) {   \
		PyErr_SetString( C2HBaseException, "handle already freed" ); \
	return NULL;  \
}


static Connection** hConns=NULL;
static HTable** hTables=NULL;
static int num_hConns=0;
static int max_hConns=0;
static int num_hTables=0;
static int max_hTables=0;

int init_hConns(int numc, int numt){
	hConns=(Connection**)malloc(sizeof(Connection*)*numc);
	hTables=(HTable**)malloc(sizeof(HTable*)*numc*numt);
	if(hConns==NULL || hTables==NULL)
	{
		return 0;
	}
	max_hConns=numc;
	max_hTables=numc*numt;

	num_hConns=0;
	num_hTables=0;
	memset(hConns, 0, sizeof(Connection*)*max_hConns);
	memset(hTables, 0, sizeof(HTable*)*max_hTables);
	return 1;

}

unsigned int next_hConn(){

	for(int i=0; i<max_hConns; i++)
	{
		if(hConns[i]==NULL)
		{
			num_hConns++;
			return i;
		}
	}
	return -1;
}
unsigned int next_hTable(){

	for(int i=0; i<max_hTables; i++)
	{
		if(hTables[i]==NULL)
		{
			num_hTables++;
			return i;
		}
	}
	return -1;
}

PyObject* pyhbase_connect(PyObject* self, PyObject* args)
{
	const char* host;
	unsigned int connId;
	if(!PyArg_ParseTuple(args, "s", &host))
		return NULL;
	for(int i=0; i<num_hConns; i++)
	{
		if(strcmp(hConns[i]->getZkhost().c_str(), host)==0)
		{
			return Py_BuildValue("i", i);
		}
	}

	connId=next_hConn();
	if(connId!=(unsigned int )(-1))
	{
		hConns[connId]=new Connection(host);
		return Py_BuildValue("i", connId);
	}
	return NULL;
}

PyObject* pyhbase_getTable(PyObject* self, PyObject* args)
{
	const char* tablename;
	unsigned int connId;
	unsigned int tableId;

	if(!PyArg_ParseTuple(args, "is", &connId, &tablename))
		return NULL;
	CHECK_CONNID(connId);

	HTable* ht=hConns[connId]->getTable(tablename);
	for(int i=0; i<num_hTables; i++)
	{
		if(hTables[i]==ht)
		{
			return Py_BuildValue("i", i);
		}
	}

	tableId=next_hTable();
	hTables[tableId]=ht;

	return Py_BuildValue("i", tableId);

}

PyObject* pyhbase_Puts(PyObject* self, PyObject* args)
{
	Py_ssize_t   _i, _j;
	PyObject*   _tableId;
	PyObject*   _puts;
	PyObject*   _rowkey;
	PyObject*   _cells;
	PyObject*   _column;
	PyObject*   _value;

	int tableId;
	char* rowkey;
	const char* column;
	char* value;
	Py_ssize_t vlen;
	string family="cf";
	string columnV;
	string DataV;

	if(PyTuple_GET_SIZE(args)!=2)
	{
		PyErr_SetString( PyExc_SystemError,
				"The number of arguments is not 2, one must be the table id, the other must be dictionary \n" );
		return NULL;
	}

	_tableId=((PyTupleObject*)args)->ob_item[0];
	if(!PyNumber_Check(_tableId))
	{
		PyErr_SetString( PyExc_SystemError,
				"The  arguments must be 1 number(long) type of TableID \n " );
		return NULL;
	}

	_puts=((PyTupleObject*)args)->ob_item[1];
	if(!PyDict_Check(_puts))
	{
		PyErr_SetString( PyExc_SystemError,
					"The  arguments must be Dict type of records \n " );
			return NULL;
	}

	tableId=PyLong_AsLong(_tableId);
	Put* put;
	list<Put*> puts;
	_i=0;
	while(PyDict_Next(_puts, &_i, &_rowkey, &_cells))
	{
#if PY_MAJOR_VERSION==3

#endif
		rowkey=PyBytes_AsString(_rowkey);
		put=new Put(rowkey);
		_j=0;
		while(PyDict_Next(_cells, &_j, &_column, &_value))
		{
#if PY_MAJOR_VERSION==3
			if(PyBytes_Check(_column))
			{
				column=PyBytes_AsString(_column);
			}
			else if(PyUnicode_Check(_column))
			{
				column=PyUnicode_AsUTF8(_column);
			}
#else
			if(PyBytes_Check(_column))
			{
				column=PyBytes_AsString(_column);
			}
			else if(PyString_Check(_column))
			{
				column=PyString_AsString(_column);
			}
#endif
			value=PyBytes_AsString(_value);
			vlen=PyBytes_Size(_value);
			DataV.assign(value,vlen);
			columnV=column;
			put->addColumn(family, columnV, DataV);
		}
		puts.push_front(put);
	}

	if(_i==1)
	{
		hTables[tableId]->Syncput(put);
	}
	else
	{
		hTables[tableId]->Syncput(puts);
	}

	list<Put*>::iterator lpit;
	for(lpit=puts.begin(); lpit!=puts.end(); lpit++)
	{
		delete ((Put*)*lpit);
	}
	puts.clear();
	return Py_BuildValue("i", 0);

}
/*
 * module setup
 */
#include "PyCHBaseDocStrings.h"

static PyMethodDef C2HBaseMethods[] ={
		{"connect", pyhbase_connect, METH_VARARGS, pyhbase_connect_doc},
		{"getTable", pyhbase_getTable, METH_VARARGS, pyhbase_getTable_doc},
		{"puts", pyhbase_Puts, METH_VARARGS, pyhbase_Puts_doc},
		{NULL,NULL}
};

#if PY_MAJOR_VERSION>=3
static struct PyModuleDef hbase_moddef ={
		PyModuleDef_HEAD_INIT,
		"c2hbase",
		NULL,
		0,
		C2HBaseMethods,
		0,
		0,
		0,
		0
};
#endif

#define ADD_INTCONSTANT(x) PyModule_AddIntConstant(module, #x, HBASE_##x)
#define ADD_INTCONSTANTZ(x) PyModule_AddIntConstant(module, #x, HB##x)

#define ADD_EXCEPTION(x) x = PyErr_NewException("c2hbase,"#x, HBaseException, NULL); \
	Py_INCREF(x) ;   \
	PyModule_AddObject(module, #x, x);

#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_c2hbase(void) {
#else
PyMODINIT_FUNC initc2hbase(void) {
#endif
	PyEval_InitThreads();

#if PY_MAJOR_VERSION >= 3
	PyObject* module = PyModule_Create(&hbase_moddef);
#else
	PyObject* module = Py_InitModule("c2hbase", C2HBaseMethods);
#endif
	if(init_hConns(8,16)==0) {
#if PY_MAJOR_VERSION >= 3
		return NULL;
#else
		return;
#endif
	}
	C2HBaseException =PyErr_NewException("c2hbase.C2HBaseException",
																PyExc_Exception,
																NULL);
	PyModule_AddObject(module, "c2hbaseException", C2HBaseException);
	Py_INCREF(C2HBaseException);

	int size=10;
	char version_str[size];
	snprintf(version_str, size, "%i.%i.%i", 0, 9, 0);
	PyModule_AddStringConstant(module, "__version__", version_str);

#if PY_MAJOR_VERSION >= 3
		return module;
#endif

}
