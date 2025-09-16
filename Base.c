#include "Base.h"
#include "Platform.h"

#define SCOPE_SYMNAME OBJECT

META_ID = 1;

DTOR { DESTROYINSTANCE; }

VTABLEDEF{VTDEF_DTOR};

#undef SCOPE_SYMNAME
