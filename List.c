#include <List.h>

#define LIST_MINIMUM_BLOCK_SIZE 16

#define SCOPE_SYMNAME LIST

META_ID = 12;

DTOR { DESTROYINSTANCE; }

VTABLESYM { VFUNC_DTOR; };
VTABLEDEF{VTDEF_DTOR};

CTOR {
    CREATEINSTANCE;
    this->Data = NULL;
    this->Size = 0;
    this->Length = 0;
}

static void __ExpandList(LIST __this) {
    if (this->Data == NULL) {
        this->Size = LIST_MINIMUM_BLOCK_SIZE;
        this->Data = __platform_AllocateMemory(sizeof(OBJECT) * LIST_MINIMUM_BLOCK_SIZE, 0);
    } else {
        OBJECT* xbuf = this->Data;
        OBJECT* nbuf = __platform_AllocateMemory(this->Size << 1, 0);
        for (size_t i = 0; i < this->Size; i++) {
            nbuf[i] = xbuf[i];
        }
        this->Size <<= 1;
        this->Data = nbuf;
        __platform_DeallocateMemory(xbuf, 0);
    }
}

MEMBER(OBJECT, At, size_t pos) { return this->Data[pos]; }

MEMBER_PROPG(size_t, Length) { return this->Length; }

MEMBER(void, Add, OBJECT object) {
    if (this->Length == this->Size) {
        __ExpandList(this);
    }
    this->Data[this->Length++] = object;
}

MEMBER(void, Insert, OBJECT object, size_t pos) {
    if (this->Length == this->Size) {
        __ExpandList(this);
    }
    for (int i = this->Length; i > pos; i--) {
        this->Data[i] = this->Data[i - 1];
    }
    this->Data[pos] = object;
    this->Length++;
}

MEMBER(OBJECT, Remove) {
    if (this->Length == 0) {
        return NULL;
    }
    return this->Data[--this->Length];
}

MEMBER(OBJECT, RemoveAt, size_t pos) {
    if (this->Length == 0) {
        return NULL;
    }
    OBJECT removed = this->Data[pos];
    for (size_t i = pos + 1; i < this->Length; i++) {
        this->Data[i - 1] = this->Data[i];
    }
    this->Length--;
    return removed;
}

#undef SCOPE_SYMNAME