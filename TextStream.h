#include "Stream.h"

#ifndef __TEXTSTREAM_H__HEADERGUARD__
#define __TEXTSTREAM_H__HEADERGUARD__

#define SCOPE_SYMNAME TEXTSTREAM

#define __INHERIT_TYPE__TEXTSTREAM OBJECT
#define __FIELDS_LIST__TEXTSTREAM                                                                                                              \
    __FIELDS_LIST__OBJECT                                                                                                                      \
    STREAM Stream;                                                                                                                             \
    bool StreamIsManaged;                                                                                                                      \
    __platform_MultiByteConverstionStateBuffer State;                                                                                          \
    byte* MbsBuffer;                                                                                                                           \
    wchar_t* WcsBuffer;
#define __VTABLE_LIST__TEXTSTREAM __VTABLE_LIST__OBJECT

TYPEDECL;

MEMBERDECL(wchar_t, Read);
MEMBERDECL(void, Write, wchar_t);

#undef SCOPE_SYMNAME

#endif
