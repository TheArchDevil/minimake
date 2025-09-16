#pragma once

#ifndef __STRING_H__HEADERGUARD__
#define __STRING_H__HEADERGUARD__

#include <Base.h>
#include <stddef.h>
#include <wchar.h>

#define SCOPE_SYMNAME STRING

#define __INHERIT_TYPE__STRING OBJECT

DECL {
    INHERIT;
    size_t Length;
    const wchar_t* Data;
};

MEMBERDECL(wchar_t, At, size_t pos);
MEMBERDECL_PROPG(size_t, Length);
MEMBERDECL_STATIC(STRING, FromBuffer, const wchar_t* buffer);
MEMBERDECL(int, CompareTo, STRING other);

#undef SCOPE_SYMNAME

#endif
