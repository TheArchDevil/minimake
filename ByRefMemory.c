#include "ByRefMemory.h"

#define SCOPE_SYMNAME BYREFMEMORY

META_ID = 3;

DTOR {
    if (this->Allocation != NULL) {
        __platform_DeallocateMemory(this->Allocation, META_TYPEID_UNDEFINED);
    }
    DESTROYINSTANCE;
}

VTABLEDEF{VTDEF_DTOR};

MEMBER_STATIC(BYREFMEMORY, Create, size_t size) {
    CREATEINSTANCE;
    this->Allocation = __platform_AllocateMemory(size, META_TYPEID_UNDEFINED);
    this->References = 1;
    return this;
}

MEMBER(void, IncreaseReference) { this->References++; }

MEMBER(void, DecreaseReference) {
    if (--this->References == 0) {
        DEL(this);
    }
}

MEMBER(void*, GetAllocation) { return this->Allocation; }

#undef SCOPE_SYMNAME