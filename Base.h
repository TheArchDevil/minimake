#pragma once

#ifndef __BASE_H__
#define __BASE_H__

#include "ObjUtils.h"
#include <stddef.h>

#define SCOPE_SYMNAME OBJECT

#define __VTABLE_LIST__OBJECT VTABLE_FUNC(OBJECT, void, $dtor);

DECL { VTABLEINCLUDE; };

#undef SCOPE_SYMNAME

#endif