#include <Base.h>

#ifndef __LIST_H__
#define __LIST_H__

#define SCOPE_SYMNAME LIST

#define __INHERIT_TYPE__LIST OBJECT
#define __FIELDS_LIST__LIST                                                                                                                    \
    __FIELDS_LIST__OBJECT                                                                                                                      \
    OBJECT* Data;                                                                                                                              \
    size_t Size;                                                                                                                               \
    size_t Length;
#define __VTABLE_LIST__LIST __VTABLE_LIST__OBJECT

TYPEDECL;

MEMBERDECL(OBJECT, At, size_t pos);
MEMBERDECL_PROPG(size_t, Length);
MEMBERDECL(void, Add, OBJECT object);
MEMBERDECL(void, Insert, OBJECT object, size_t pos);
MEMBERDECL(OBJECT, Remove);
MEMBERDECL(OBJECT, RemoveAt, size_t pos);

#undef SCOPE_SYMNAME

#endif
