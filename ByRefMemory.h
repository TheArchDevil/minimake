#include "Base.h"

#define SCOPE_SYMNAME BYREFMEMORY

#define __INHERIT_TYPE__BYREFMEMORY OBJECT

DECL {
    INHERIT;
    void* Allocation;
    size_t References;
};

MEMBERDECL_STATIC(BYREFMEMORY, Create, size_t size);

MEMBERDECL(void, IncreaseReference);
MEMBERDECL(void, DecreaseReference);

MEMBERDECL(void*, GetAllocation);

#undef SCOPE_SYMNAME