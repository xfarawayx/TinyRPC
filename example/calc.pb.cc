// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: calc.proto

#include "calc.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR AddRequest::AddRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.a_)*/0
  , /*decltype(_impl_.b_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AddRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AddRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~AddRequestDefaultTypeInternal() {}
  union {
    AddRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AddRequestDefaultTypeInternal _AddRequest_default_instance_;
PROTOBUF_CONSTEXPR AddResponse::AddResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.result_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AddResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AddResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~AddResponseDefaultTypeInternal() {}
  union {
    AddResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AddResponseDefaultTypeInternal _AddResponse_default_instance_;
static ::_pb::Metadata file_level_metadata_calc_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_calc_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_calc_2eproto[1];

const uint32_t TableStruct_calc_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::AddRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::AddRequest, _impl_.a_),
  PROTOBUF_FIELD_OFFSET(::AddRequest, _impl_.b_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::AddResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::AddResponse, _impl_.result_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::AddRequest)},
  { 8, -1, -1, sizeof(::AddResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_AddRequest_default_instance_._instance,
  &::_AddResponse_default_instance_._instance,
};

const char descriptor_table_protodef_calc_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ncalc.proto\"\"\n\nAddRequest\022\t\n\001a\030\001 \001(\005\022\t\n"
  "\001b\030\002 \001(\005\"\035\n\013AddResponse\022\016\n\006result\030\001 \001(\0052"
  "5\n\021CalculatorService\022 \n\003Add\022\013.AddRequest"
  "\032\014.AddResponseB\003\200\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_calc_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_calc_2eproto = {
    false, false, 147, descriptor_table_protodef_calc_2eproto,
    "calc.proto",
    &descriptor_table_calc_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_calc_2eproto::offsets,
    file_level_metadata_calc_2eproto, file_level_enum_descriptors_calc_2eproto,
    file_level_service_descriptors_calc_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_calc_2eproto_getter() {
  return &descriptor_table_calc_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_calc_2eproto(&descriptor_table_calc_2eproto);

// ===================================================================

class AddRequest::_Internal {
 public:
};

AddRequest::AddRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:AddRequest)
}
AddRequest::AddRequest(const AddRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  AddRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.a_){}
    , decltype(_impl_.b_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.a_, &from._impl_.a_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.b_) -
    reinterpret_cast<char*>(&_impl_.a_)) + sizeof(_impl_.b_));
  // @@protoc_insertion_point(copy_constructor:AddRequest)
}

inline void AddRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.a_){0}
    , decltype(_impl_.b_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

AddRequest::~AddRequest() {
  // @@protoc_insertion_point(destructor:AddRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void AddRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void AddRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void AddRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:AddRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.a_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.b_) -
      reinterpret_cast<char*>(&_impl_.a_)) + sizeof(_impl_.b_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AddRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 a = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.a_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 b = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.b_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* AddRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:AddRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 a = 1;
  if (this->_internal_a() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_a(), target);
  }

  // int32 b = 2;
  if (this->_internal_b() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_b(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:AddRequest)
  return target;
}

size_t AddRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:AddRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 a = 1;
  if (this->_internal_a() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_a());
  }

  // int32 b = 2;
  if (this->_internal_b() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_b());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AddRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    AddRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AddRequest::GetClassData() const { return &_class_data_; }


void AddRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<AddRequest*>(&to_msg);
  auto& from = static_cast<const AddRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:AddRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_a() != 0) {
    _this->_internal_set_a(from._internal_a());
  }
  if (from._internal_b() != 0) {
    _this->_internal_set_b(from._internal_b());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AddRequest::CopyFrom(const AddRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:AddRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddRequest::IsInitialized() const {
  return true;
}

void AddRequest::InternalSwap(AddRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(AddRequest, _impl_.b_)
      + sizeof(AddRequest::_impl_.b_)
      - PROTOBUF_FIELD_OFFSET(AddRequest, _impl_.a_)>(
          reinterpret_cast<char*>(&_impl_.a_),
          reinterpret_cast<char*>(&other->_impl_.a_));
}

::PROTOBUF_NAMESPACE_ID::Metadata AddRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_calc_2eproto_getter, &descriptor_table_calc_2eproto_once,
      file_level_metadata_calc_2eproto[0]);
}

// ===================================================================

class AddResponse::_Internal {
 public:
};

AddResponse::AddResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:AddResponse)
}
AddResponse::AddResponse(const AddResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  AddResponse* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.result_ = from._impl_.result_;
  // @@protoc_insertion_point(copy_constructor:AddResponse)
}

inline void AddResponse::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

AddResponse::~AddResponse() {
  // @@protoc_insertion_point(destructor:AddResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void AddResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void AddResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void AddResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:AddResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.result_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AddResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.result_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* AddResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:AddResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_result(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:AddResponse)
  return target;
}

size_t AddResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:AddResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_result());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AddResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    AddResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AddResponse::GetClassData() const { return &_class_data_; }


void AddResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<AddResponse*>(&to_msg);
  auto& from = static_cast<const AddResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:AddResponse)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_result() != 0) {
    _this->_internal_set_result(from._internal_result());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AddResponse::CopyFrom(const AddResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:AddResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddResponse::IsInitialized() const {
  return true;
}

void AddResponse::InternalSwap(AddResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.result_, other->_impl_.result_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AddResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_calc_2eproto_getter, &descriptor_table_calc_2eproto_once,
      file_level_metadata_calc_2eproto[1]);
}

// ===================================================================

CalculatorService::~CalculatorService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* CalculatorService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_calc_2eproto);
  return file_level_service_descriptors_calc_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* CalculatorService::GetDescriptor() {
  return descriptor();
}

void CalculatorService::Add(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::AddRequest*,
                         ::AddResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Add() not implemented.");
  done->Run();
}

void CalculatorService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_calc_2eproto[0]);
  switch(method->index()) {
    case 0:
      Add(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::AddRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::AddResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& CalculatorService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::AddRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& CalculatorService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::AddResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

CalculatorService_Stub::CalculatorService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
CalculatorService_Stub::CalculatorService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
CalculatorService_Stub::~CalculatorService_Stub() {
  if (owns_channel_) delete channel_;
}

void CalculatorService_Stub::Add(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::AddRequest* request,
                              ::AddResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::AddRequest*
Arena::CreateMaybeMessage< ::AddRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::AddRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::AddResponse*
Arena::CreateMaybeMessage< ::AddResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::AddResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
