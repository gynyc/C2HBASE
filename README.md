# C2HBASE
implement native client for hbase  with c++,based on hbase 2.2 above version (current hbase master is 2.2 version later) 
There are some diffrent between this project and apache/hbase native client.

First is library rely , apache/hbase native client rely on GFLAGS ,FOLLY_LIBRARIES,and so on.


C2HBASE support Python visit hbase server.

This project  rely  these moudles list as follows:

1 hbase protobuf files,in the personal Envinment,
 
   protoc --version

   libprotoc 3.9.1

  you can use other version, and mentions that hbase 1.x use libprotoc 2.x.x  , hbase 2.x use libprotoc 3.x.x
 
  use protoc product(convert *.proto) *.cc and *.h and g++ compile lib CHBaseProto.a  with  -std=c++0x -fPIC.

2 zookeeper

3 poco lib

 
