#pragma once

#ifndef __BASE_H__
#define __BASE_H__

#include "ObjUtils.h"
#include <stddef.h>

#define SCOPE_SYMNAME OBJECT

#define __FIELDS_LIST__OBJECT const void* __vtable;
#define __VTABLE_LIST__OBJECT VTABLE_FUNC(OBJECT, void, $dtor);

TYPEDECL;

MEMBERDECL(void, $__special_dtor);

typedef unsigned char byte;

#undef SCOPE_SYMNAME

#endif