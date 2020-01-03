// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Encryption.proto

#include "Encryption.pb.h"

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
namespace hbase {
namespace pb {
class WrappedKeyDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<WrappedKey> _instance;
} _WrappedKey_default_instance_;
}  // namespace pb
}  // namespace hbase
static void InitDefaultsscc_info_WrappedKey_Encryption_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::hbase::pb::_WrappedKey_default_instance_;
    new (ptr) ::hbase::pb::WrappedKey();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::hbase::pb::WrappedKey::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_WrappedKey_Encryption_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_WrappedKey_Encryption_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Encryption_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Encryption_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Encryption_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Encryption_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, algorithm_),
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, length_),
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, data_),
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, iv_),
  PROTOBUF_FIELD_OFFSET(::hbase::pb::WrappedKey, hash_),
  0,
  4,
  1,
  2,
  3,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::hbase::pb::WrappedKey)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::hbase::pb::_WrappedKey_default_instance_),
};

const char descriptor_table_protodef_Encryption_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020Encryption.proto\022\010hbase.pb\"W\n\nWrappedK"
  "ey\022\021\n\talgorithm\030\001 \002(\t\022\016\n\006length\030\002 \002(\r\022\014\n"
  "\004data\030\003 \002(\014\022\n\n\002iv\030\004 \001(\014\022\014\n\004hash\030\005 \001(\014BC\n"
  "*org.apache.hadoop.hbase.protobuf.genera"
  "tedB\020EncryptionProtosH\001\240\001\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Encryption_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_Encryption_2eproto_sccs[1] = {
  &scc_info_WrappedKey_Encryption_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Encryption_2eproto_once;
static bool descriptor_table_Encryption_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Encryption_2eproto = {
  &descriptor_table_Encryption_2eproto_initialized, descriptor_table_protodef_Encryption_2eproto, "Encryption.proto", 186,
  &descriptor_table_Encryption_2eproto_once, descriptor_table_Encryption_2eproto_sccs, descriptor_table_Encryption_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_Encryption_2eproto::offsets,
  file_level_metadata_Encryption_2eproto, 1, file_level_enum_descriptors_Encryption_2eproto, file_level_service_descriptors_Encryption_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_Encryption_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_Encryption_2eproto), true);
namespace hbase {
namespace pb {

// ===================================================================

void WrappedKey::InitAsDefaultInstance() {
}
class WrappedKey::_Internal {
 public:
  using HasBits = decltype(std::declval<WrappedKey>()._has_bits_);
  static void set_has_algorithm(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_length(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_data(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_iv(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_hash(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
};

WrappedKey::WrappedKey()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:hbase.pb.WrappedKey)
}
WrappedKey::WrappedKey(const WrappedKey& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  algorithm_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_algorithm()) {
    algorithm_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.algorithm_);
  }
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_data()) {
    data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  iv_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_iv()) {
    iv_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.iv_);
  }
  hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.has_hash()) {
    hash_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.hash_);
  }
  length_ = from.length_;
  // @@protoc_insertion_point(copy_constructor:hbase.pb.WrappedKey)
}

void WrappedKey::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_WrappedKey_Encryption_2eproto.base);
  algorithm_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  iv_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  length_ = 0u;
}

WrappedKey::~WrappedKey() {
  // @@protoc_insertion_point(destructor:hbase.pb.WrappedKey)
  SharedDtor();
}

void WrappedKey::SharedDtor() {
  algorithm_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  iv_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  hash_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void WrappedKey::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const WrappedKey& WrappedKey::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_WrappedKey_Encryption_2eproto.base);
  return *internal_default_instance();
}


void WrappedKey::Clear() {
// @@protoc_insertion_point(message_clear_start:hbase.pb.WrappedKey)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      algorithm_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      data_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      iv_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000008u) {
      hash_.ClearNonDefaultToEmptyNoArena();
    }
  }
  length_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* WrappedKey::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string algorithm = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8Verify(mutable_algorithm(), ptr, ctx, "hbase.pb.WrappedKey.algorithm");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint32 length = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_length(&has_bits);
          length_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required bytes data = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_data(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes iv = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_iv(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes hash = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(mutable_hash(), ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool WrappedKey::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:hbase.pb.WrappedKey)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string algorithm = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_algorithm()));
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
            this->algorithm().data(), static_cast<int>(this->algorithm().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::PARSE,
            "hbase.pb.WrappedKey.algorithm");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 length = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {
          _Internal::set_has_length(&_has_bits_);
          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   ::PROTOBUF_NAMESPACE_ID::uint32, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT32>(
                 input, &length_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required bytes data = 3;
      case 3: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (26 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bytes iv = 4;
      case 4: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (34 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadBytes(
                input, this->mutable_iv()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bytes hash = 5;
      case 5: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (42 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadBytes(
                input, this->mutable_hash()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:hbase.pb.WrappedKey)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:hbase.pb.WrappedKey)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void WrappedKey::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:hbase.pb.WrappedKey)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string algorithm = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->algorithm().data(), static_cast<int>(this->algorithm().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "hbase.pb.WrappedKey.algorithm");
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->algorithm(), output);
  }

  // required uint32 length = 2;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32(2, this->length(), output);
  }

  // required bytes data = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->data(), output);
  }

  // optional bytes iv = 4;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->iv(), output);
  }

  // optional bytes hash = 5;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->hash(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:hbase.pb.WrappedKey)
}

::PROTOBUF_NAMESPACE_ID::uint8* WrappedKey::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:hbase.pb.WrappedKey)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string algorithm = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->algorithm().data(), static_cast<int>(this->algorithm().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "hbase.pb.WrappedKey.algorithm");
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringToArray(
        1, this->algorithm(), target);
  }

  // required uint32 length = 2;
  if (cached_has_bits & 0x00000010u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->length(), target);
  }

  // required bytes data = 3;
  if (cached_has_bits & 0x00000002u) {
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesToArray(
        3, this->data(), target);
  }

  // optional bytes iv = 4;
  if (cached_has_bits & 0x00000004u) {
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesToArray(
        4, this->iv(), target);
  }

  // optional bytes hash = 5;
  if (cached_has_bits & 0x00000008u) {
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBytesToArray(
        5, this->hash(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hbase.pb.WrappedKey)
  return target;
}

size_t WrappedKey::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:hbase.pb.WrappedKey)
  size_t total_size = 0;

  if (has_algorithm()) {
    // required string algorithm = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->algorithm());
  }

  if (has_data()) {
    // required bytes data = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->data());
  }

  if (has_length()) {
    // required uint32 length = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->length());
  }

  return total_size;
}
size_t WrappedKey::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:hbase.pb.WrappedKey)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000013) ^ 0x00000013) == 0) {  // All required fields are present.
    // required string algorithm = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->algorithm());

    // required bytes data = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->data());

    // required uint32 length = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->length());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000000cu) {
    // optional bytes iv = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->iv());
    }

    // optional bytes hash = 5;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->hash());
    }

  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void WrappedKey::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:hbase.pb.WrappedKey)
  GOOGLE_DCHECK_NE(&from, this);
  const WrappedKey* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<WrappedKey>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:hbase.pb.WrappedKey)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:hbase.pb.WrappedKey)
    MergeFrom(*source);
  }
}

void WrappedKey::MergeFrom(const WrappedKey& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:hbase.pb.WrappedKey)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      algorithm_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.algorithm_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      data_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.data_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      iv_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.iv_);
    }
    if (cached_has_bits & 0x00000008u) {
      _has_bits_[0] |= 0x00000008u;
      hash_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.hash_);
    }
    if (cached_has_bits & 0x00000010u) {
      length_ = from.length_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void WrappedKey::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:hbase.pb.WrappedKey)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WrappedKey::CopyFrom(const WrappedKey& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:hbase.pb.WrappedKey)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WrappedKey::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000013) != 0x00000013) return false;
  return true;
}

void WrappedKey::InternalSwap(WrappedKey* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  algorithm_.Swap(&other->algorithm_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  data_.Swap(&other->data_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  iv_.Swap(&other->iv_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  hash_.Swap(&other->hash_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(length_, other->length_);
}

::PROTOBUF_NAMESPACE_ID::Metadata WrappedKey::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
}  // namespace hbase
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::hbase::pb::WrappedKey* Arena::CreateMaybeMessage< ::hbase::pb::WrappedKey >(Arena* arena) {
  return Arena::CreateInternal< ::hbase::pb::WrappedKey >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
