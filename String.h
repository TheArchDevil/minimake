#pragma once

#ifndef __STRING_H__HEADERGUARD__
#define __STRING_H__HEADERGUARD__

#include <ByRefMemory.h>
#include <stddef.h>
#include <wchar.h>

#define SCOPE_SYMNAME STRING

#define __INHERIT_TYPE__STRING OBJECT
#define __FIELDS_LIST__STRING                                                                                                                  \
    __FIELDS_LIST__OBJECT                                                                                                                      \
    size_t Length;                                                                                                                             \
    BYREFMEMORY Memory;                                                                                                                        \
    const wchar_t* Buffer;
#define __VTABLE_LIST__STRING __VTABLE_LIST__OBJECT

TYPEDECL;

MEMBERDECL(wchar_t, At, size_t pos);
MEMBERDECL_PROPG(size_t, Length);
MEMBERDECL_STATIC(STRING, FromBuffer, const wchar_t* buffer);
MEMBERDECL(int, CompareTo, STRING other);
MEMBERDECL(STRING, Substring, size_t begin, size_t count);
MEMBERDECL(STRING, Trim);
MEMBERDECL(STRING, TrimStart);
MEMBERDECL(STRING, TrimEnd);
MEMBERDECL_STATIC(bool, IsNullOrEmpty, STRING str);

#undef SCOPE_SYMNAME

#endif
