#pragma once

#ifndef __FILE_STREAM_H__HEADERGUARD__
#define __FILE_STREAM_H__HEADERGUARD__

#include "Stream.h"

#define SCOPE_SYMNAME FILESTREAM

#define __INHERIT_TYPE__FILESTREAM STREAM
#define __FIELDS_LIST__FILESTREAM                                                                                                              \
    __VTABLE_LIST__STREAM                                                                                                                      \
    int fd;
#define __VTABLE_LIST__FILESTREAM __VTABLE_LIST__STREAM

TYPEDECL;

#undef SCOPE_SYMNAME

#endif