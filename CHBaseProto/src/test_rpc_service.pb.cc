// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test_rpc_service.proto

#include "test_rpc_service.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_test_5frpc_5fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_test_5frpc_5fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_test_5frpc_5fservice_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_test_5frpc_5fservice_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_test_5frpc_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026test_rpc_service.proto\032\ntest.proto2\212\002\n"
  "\024TestProtobufRpcProto\022/\n\004ping\022\022.EmptyReq"
  "uestProto\032\023.EmptyResponseProto\022-\n\004echo\022\021"
  ".EchoRequestProto\032\022.EchoResponseProto\0220\n"
  "\005error\022\022.EmptyRequestProto\032\023.EmptyRespon"
  "seProto\0220\n\005pause\022\022.PauseRequestProto\032\023.E"
  "mptyResponseProto\022.\n\004addr\022\022.EmptyRequest"
  "Proto\032\022.AddrResponseProtoBL\n.org.apache."
  "hadoop.hbase.ipc.protobuf.generatedB\024Tes"
  "tRpcServiceProtos\210\001\001\240\001\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_test_5frpc_5fservice_2eproto_deps[1] = {
  &::descriptor_table_test_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_test_5frpc_5fservice_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_test_5frpc_5fservice_2eproto_once;
static bool descriptor_table_test_5frpc_5fservice_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_5frpc_5fservice_2eproto = {
  &descriptor_table_test_5frpc_5fservice_2eproto_initialized, descriptor_table_protodef_test_5frpc_5fservice_2eproto, "test_rpc_service.proto", 383,
  &descriptor_table_test_5frpc_5fservice_2eproto_once, descriptor_table_test_5frpc_5fservice_2eproto_sccs, descriptor_table_test_5frpc_5fservice_2eproto_deps, 0, 1,
  schemas, file_default_instances, TableStruct_test_5frpc_5fservice_2eproto::offsets,
  file_level_metadata_test_5frpc_5fservice_2eproto, 0, file_level_enum_descriptors_test_5frpc_5fservice_2eproto, file_level_service_descriptors_test_5frpc_5fservice_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_test_5frpc_5fservice_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_test_5frpc_5fservice_2eproto), true);

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
