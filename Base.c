#include "Base.h"
#include "Platform.h"

#define SCOPE_SYMNAME OBJECT

META_ID = 1;

DTOR { DESTROYINSTANCE; }

VTABLEDEF{VTDEF_DTOR};

MEMBER(void, $__special_dtor) { WRAP_VIRTUAL_CALL(void, $dtor); }

#undef SCOPE_SYMNAME
