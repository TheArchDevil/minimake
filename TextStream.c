#include "TextStream.h"
#include "String.h"
#include <wchar.h>

#define SCOPE_SYMNAME TEXTSTREAM

DTOR {
    if (this->StreamIsManaged) {
        DEL(this->Stream);
    }
    DESTROYINSTANCE;
}

INIT { BASEINIT; }

VTABLEDEF{VTDEF_DTOR};

MEMBER(void, WriteBuffer, wchar_t* buffer, int count) {
    mbstate_t state;
    size_t clen = __platform_MultiByteToWideChar(NULL, buffer, count, 0);
    char* cbuf = __platform_AllocateMemory(sizeof(char) * (clen + 1), META_TYPEID_UNDEFINED);
    __platform_MultiByteToWideChar(cbuf, buffer, count, clen + 1);
    $(STREAM, this->Stream, WriteBuffer, cbuf, clen);
    __platform_DeallocateMemory(cbuf, META_TYPEID_UNDEFINED);
}
MEMBER(wchar_t, Read) { $(STREAM, this->Stream, Read); }
MEMBER(void, Write, wchar_t c) { _$(this, WriteBuffer, &c, 1); }
MEMBER(void, WriteString, STRING str) {
    wchar_t* rawptr = $(STRING, str, RawPtr);
    size_t len = $get(STRING, str, Length);
    _$(this, WriteBuffer, rawptr, len);
}

#undef SCOPE_SYMNAME