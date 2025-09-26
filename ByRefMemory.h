#include "Base.h"

#define SCOPE_SYMNAME BYREFMEMORY

#define __INHERIT_TYPE__BYREFMEMORY OBJECT

#define __FIELDS_LIST__BYREFMEMORY                                                                                                             \
    __FIELDS_LIST__OBJECT                                                                                                                      \
    void* Allocation;                                                                                                                          \
    size_t References;
#define __VTABLE_LIST__BYREFMEMORY __VTABLE_LIST__OBJECT

TYPEDECL;

MEMBERDECL_STATIC(BYREFMEMORY, Create, size_t size);

MEMBERDECL(void, IncreaseReference);
MEMBERDECL(void, DecreaseReference);

MEMBERDECL(void*, GetAllocation);

#undef SCOPE_SYMNAME