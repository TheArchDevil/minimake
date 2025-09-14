#pragma once

#ifndef __STRING_H__
#define __STRING_H__

#include <Base.h>
#include <stddef.h>
#include <wchar.h>

#define SCOPE_SYMNAME STRING

DECL {
    INHERIT(OBJECT);
    size_t Length;
    const wchar_t* Data;
};

DEFINETYPE;

MEMBERDECL(wchar_t, At, size_t pos);
MEMBERDECL_PROPG(size_t, Length);
MEMBERDECL_STATIC(STRING, FromBuffer, const wchar_t* buffer);

#undef SCOPE_SYMNAME

#endif
