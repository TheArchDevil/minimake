#include <String.h>

#define SCOPE_SYMNAME STRING

META_ID = 9;

DTOR {
    __platform_DeallocateMemory(this, 0);
    DESTROYINSTANCE;
}

VTABLESYM { VTABLE_FUNC(STRING, void, $dtor); };
VTABLEDEF{VTDEF_DTOR};

MEMBER(wchar_t, At, size_t pos) { return this->Data[pos]; }

MEMBER_PROPG(size_t, Length) { return this->Length; }

MEMBER_STATIC(STRING, FromBuffer, const wchar_t* buffer) {
    CREATEINSTANCE;
    size_t count = wcslen(buffer);
    wchar_t* nbuf = __platform_AllocateMemory(count + 1, 0);
    this->Length = count;
    wcscpy(nbuf, buffer);
    this->Data = nbuf;
    this->Length = count;
    return this;
}

#undef SCOPE_SYMNAME