/*
 * Mutation.h
 *
 *  Created on: 2020年1月19日
 *      Author: stephen
 */

#ifndef MUTATION_H_
#define MUTATION_H_
#include <string>
#include <list>
#include <map>
#include <CHBaseProto/Client.pb.h>
#include "Cell.h"
#include "Row.h"

using namespace std;
//using namespace google::protobuf;
using namespace hbase::pb;


namespace CHBase {

enum Durability
{
	USE_DEFAULT,
	SKIP_WAL,
	ASYNC_WAL,
	FSYNC_WAL
};


class Mutation : public Row{
public:
	Mutation();
	virtual ~Mutation();
	long heapSize();
	/*
	void row2CV(MutationProto* pmut)
	void show();
	*/
	//Mutation* addColumn(string& family, string& qualifier, string& value);

private:
	/*
	string row;
	map<string, list<Cell*> > familyMap;
	*/
public:
	static const long MUTATION_OVERHEAD=56;
protected:
	const string CONSUMED_CLUSTER_IDS="_cs.id";
	const string OP_ATTRIBUTE_TTL="_ttl";
	const string RETURN_RESULTS="_rr_";
	long ts=(unsigned long)-1L;
	Durability durability=USE_DEFAULT;

};

} /* namespace CHBase */

#endif /* MUTATION_H_ */
