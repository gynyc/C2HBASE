from distutils.core import setup, Extension

hbase_basedir = "./"

hbasemodule = Extension("c2hbase",
                            sources=[hbase_basedir+"src/PyCHBase.cpp"],
                            extra_compile_args=["-std=c++0x","-Wdeprecated-register"],
                            include_dirs=[
                            					"/usr/include",
                             				"/usr/local/include",
                             				"/usr/local/include/zookeeper",
                                          	"/usr/local/include/CHBase",
                                          	"/usr/local/include/CHBaseProto"
                                           ],
                            libraries=["CHBase",
                            		   "CHBaseProto",
                            		   "zookeeper_mt",
                            		   "protobuf",
                            		   "PocoUtil",
                            		   "PocoNet",
                            		   "PocoFoundation"],
                            library_dirs=[
                                          "/usr/lib",
                                          "/usr/local/lib"
                                          ])

setup( name="c2hbase",
       version = "0.1",
       description = "hbase Python bindings",
       ext_modules=[hbasemodule] )

