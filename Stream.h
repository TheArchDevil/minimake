#pragma once

#ifndef __STREAM_H__HEADERGUARD__
#define __STREAM_H__HEADERGUARD__

#include "Base.h"

#define SCOPE_SYMNAME STREAM

#define __INHERIT_TYPE__STREAM OBJECT
#define __FIELDS_LIST__STREAM __FIELDS_LIST__OBJECT
#define __VTABLE_LIST__STREAM                                                                                                                  \
    __VTABLE_LIST__OBJECT                                                                                                                      \
    VTABLE_FUNC(STREAM, bool, IsReadable);                                                                                                     \
    VTABLE_FUNC(STREAM, bool, IsWritable);                                                                                                     \
    VTABLE_FUNC(STREAM, bool, IsSeekable);                                                                                                     \
    VTABLE_FUNC(STREAM, byte, Read);                                                                                                           \
    VTABLE_FUNC(STREAM, void, Write, byte data);                                                                                               \
    VTABLE_FUNC(STREAM, void, Seek, size_t offset, unsigned seekMode);                                                                         \
    VTABLE_FUNC(STREAM, size_t, ReadBuffer, byte* buffer, size_t size);                                                                        \
    VTABLE_FUNC(STREAM, size_t, WriteBuffer, byte* buffer, size_t size);                                                                       \
    VTABLE_FUNC(STREAM, bool, IsEndOfStream);                                                                                                  \
    VTABLE_FUNC(STREAM, void, Close);

TYPEDECL;

MEMBERDECL(bool, IsReadable);
MEMBERDECL(bool, IsWritable);
MEMBERDECL(bool, IsSeekable);
MEMBERDECL(byte, Read);
MEMBERDECL(void, Write, byte data);
MEMBERDECL(size_t, ReadBuffer, byte* buffer, size_t size);
MEMBERDECL(size_t, WriteBuffer, byte* buffer, size_t size);
MEMBERDECL(void, Seek, size_t offset, unsigned seekMode);
MEMBERDECL(bool, IsEndOfStream);
MEMBERDECL(void, Close);

#undef SCOPE_SYMNAME

#endif