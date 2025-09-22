#pragma once

#ifndef __OBJUTILS_H__
#define __OBJUTILS_H__

#include "Platform.h"
#include <stdint.h>

#define PROPG_NAME(prop) prop##$getter
#define PROPS_NAME(prop) prop##$setter

#define __SYM(x) struct __objtype_##x
#define SYM(x) __SYM(x) // Object symbol definition
#define PSYM(x) SYM(x)*
#define SIZE(x) sizeof(SYM(x))

#define __BASE_TYPE_OF(x) __INHERIT_TYPE__##x
#define BASE_TYPE_OF(x) __BASE_TYPE_OF(x)

#define __OBJFIELDS_MACRO_NAME(x) __FIELDS_LIST__##x
#define OBJFIELDS_MACRO_NAME(x) __OBJFIELDS_MACRO_NAME(x)

#define __SYMID_CONST_NAME(type) __objmeta_##type##$__id
#define SYMID_CONST_NAME(type) __SYMID_CONST_NAME(type)
#define SYMID_CONST(type) const uint32_t SYMID_CONST_NAME(type)
#define SYMDECL(type)                                                                                                                          \
    extern SYMID_CONST(type);                                                                                                                  \
    typedef SYM(type)

#define DECL                                                                                                                                   \
    DEFINETYPE;                                                                                                                                \
    SYMDECL(SCOPE_SYMNAME)

#define TYPEDECL                                                                                                                               \
    DEFINETYPE;                                                                                                                                \
    SYMDECL(SCOPE_SYMNAME) { OBJFIELDS_MACRO_NAME(SCOPE_SYMNAME); }

#define OBJTYPE(obj) (*(uint32_t*)((char*)obj - 4))
#define TYPEID(type) SYMID_CONST_NAME(type)

#define INHERIT                                                                                                                                \
    union {                                                                                                                                    \
        VTABLEINCLUDE;                                                                                                                         \
        BASE_TYPE_OF(SCOPE_SYMNAME) Base;                                                                                                      \
    }

#define __VTABLE_NAME(x) __objtype_##x##$__vtable
#define VTABLE_NAME(x) __VTABLE_NAME(x)
#define VTABLESYM_NAME(x) struct VTABLE_NAME(x)
#define VTABLESYM VTABLESYM_NAME(SCOPE_SYMNAME)
#define __VTABLECONSTNAME(x) __objvtable_##x
#define VTABLECONSTNAME(x) __VTABLECONSTNAME(x)
#define VTABLEDEF                                                                                                                              \
    VTABLESYM{VTABLE_LIST_OF(SCOPE_SYMNAME)};                                                                                                  \
    const VTABLESYM VTABLECONSTNAME(SCOPE_SYMNAME) =
#define VTABLEINCLUDE void* __vtable
#define VTABLE(type, x, fn) (((VTABLESYM*)x)->fn)

#define VTABLE_FUNC(obj, type, name, ...) type (*name)(obj, ##__VA_ARGS__) // Define a function
#define VTDEF_DTOR .$dtor = DTOR_NAME(SCOPE_SYMNAME)

#define VTDEF_FUNC(x) .x = OBJMEMBER_VIRTUAL_NAME(SCOPE_SYMNAME, x)

#define VFUNC(type, name, ...) VTABLE_FUNC(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)
#define VFUNC_DTOR VFUNC(void, $dtor)

// #define PROPG(obj, type, name) type (*PROPG_NAME(name))(PSYM(obj))       // Define a get-only property
// #define PROPS(obj, type, name) void (*PROPS_NAME(name))(PSYM(obj), type) // Define a set-only property
 // #define PROPA(obj, type, name) \
//     PROPG(obj, type, name); \
 PROPS(obj, type, name) // Define a get-set property
#define DEFINETYPE typedef void* SCOPE_SYMNAME

#define __OBJMEMBER_PROPG_NAME(obj, name) __objfunc_##obj##$__prop_##name##$__getter
#define OBJMEMBER_PROPG_NAME(obj, name) __OBJMEMBER_PROPG_NAME(obj, name)
#define __OBJMEMBER_PROPS_NAME(obj, name) __objfunc_##obj##$__prop_##name##$__setter
#define OBJMEMBER_PROPS_NAME(obj, name) __OBJMEMBER_PROPS_NAME(obj, name)
#define __OBJMEMBER_NAME(obj, name) __objfunc_##obj##$__memfn_##name
#define OBJMEMBER_NAME(obj, name) __OBJMEMBER_NAME(obj, name)
#define __OBJMEMBER_NAME(obj, name) __objfunc_##obj##$__memfn_##name
#define OBJMEMBER_NAME(obj, name) __OBJMEMBER_NAME(obj, name)
#define __OBJMEMBER_VIRTUAL_NAME(obj, name) __objfunc_##obj##$__memfn_virtual_##name
#define OBJMEMBER_VIRTUAL_NAME(obj, name) __OBJMEMBER_VIRTUAL_NAME(obj, name)
#define __OBJMEMBER_STATIC_NAME(obj, name) __objfunc_##obj##$__memfn_static_##name
#define OBJMEMBER_STATIC_NAME(obj, name) __OBJMEMBER_STATIC_NAME(obj, name)

#define OBJMEMBERDECL_PROPG(obj, type, name) type OBJMEMBER_PROPG_NAME(obj, name)(obj)
#define OBJMEMBERDECL_PROPS(obj, type, name) void OBJMEMBER_PROPS_NAME(obj, name)(obj, type value)
#define OBJMEMBERDECL_PROPGS(obj, type, name)                                                                                                  \
    OBJMEMBERDECL_PROPG(obj, type name);                                                                                                       \
    OBJMEMBERDECL_PROPS(obj, type name)
#define OBJMEMBERDECL(obj, type, name, ...) type OBJMEMBER_NAME(obj, name)(obj, ##__VA_ARGS__)
#define OBJMEMBERDECL_STATIC(obj, type, name, ...) type OBJMEMBER_STATIC_NAME(obj, name)(__VA_ARGS__)

#define MEMBERDECL_PROPG(type, name) OBJMEMBERDECL_PROPG(SCOPE_SYMNAME, type, name)
#define MEMBERDECL_PROPS(type, name) OBJMEMBERDECL_PROPS(SCOPE_SYMNAME, type, name)
#define MEMBERDECL_PROPGS(type, name) OBJMEMBERDECL_PROPGS(SCOPE_SYMNAME, type, name)
#define MEMBERDECL(type, name, ...) OBJMEMBERDECL(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)
#define MEMBERDECL_STATIC(type, name, ...) OBJMEMBERDECL_STATIC(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)

#define OBJMEMBERDEF_PROPG(obj, type, name) type OBJMEMBER_PROPG_NAME(obj, name)(obj __this)
#define OBJMEMBERDEF_PROPS(obj, type, name) void OBJMEMBER_PROPS_NAME(obj, name)(obj __this, type value)
#define OBJMEMBERDEF(obj, type, name, ...) type OBJMEMBER_NAME(obj, name)(obj __this, ##__VA_ARGS__)
#define OBJMEMBERDEF_STATIC(obj, type, name, ...) type OBJMEMBER_STATIC_NAME(obj, name)(__VA_ARGS__)
#define OBJMEMBERDEF_VIRTUAL(obj, type, name, ...) type OBJMEMBER_VIRTUAL_NAME(obj, name)(obj __this, ##__VA_ARGS__)

#define MEMBER_PROPG(type, name) OBJMEMBERDEF_PROPG(SCOPE_SYMNAME, type, name)
#define MEMBER_PROPS(type, name) OBJMEMBERDEF_PROPS(SCOPE_SYMNAME, type, name)
#define MEMBER(type, name, ...) OBJMEMBERDEF(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)
#define MEMBER_STATIC(type, name, ...) OBJMEMBERDEF_STATIC(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)
#define MEMBER_VIRTUAL(type, name, ...) OBJMEMBERDEF_VIRTUAL(SCOPE_SYMNAME, type, name, ##__VA_ARGS__)
#define WRAP_VIRTUAL_CALL(type, name, ...) return VTABLE(SCOPE_SYMNAME, this, name)(__this, ##__VA_ARGS__)

#define META_ID SYMID_CONST(SCOPE_SYMNAME)

#define this ((PSYM(SCOPE_SYMNAME))(__this))

#define T(x) ((PSYM(SCOPE_SYMNAME))(x))

#define __VTABLE_LIST_OF(x) __VTABLE_LIST__##x
#define VTABLE_LIST_OF(x) __VTABLE_LIST_OF(x)

// #define VFNIMPL_NAME(obj, name) __objfunc_##obj##$impl_virtual_##name          // Name of implementation for a virtual method
// #define VPGIMPL_NAME(obj, name) __objfunc_##obj##$impl_virtual_##name##$getter // Name of implementation for a virtual property getter
// #define VPSIMPL_NAME(obj, name) __objfunc_##obj##$impl_virtual_##name##$setter // Name of implementation for a virtual property setter
// #define VFNIMPL(obj, type, name, ...) static type VFNIMPL_NAME(obj, name)(PSYM(obj) this, ##__VA_ARGS__)
// #define VPGIMPL(obj, type, name) static type VPGIMPL_NAME(obj, name)(PSYM(obj) this)
// #define VPSIMPL(obj, type, name) static void VPSIMPL_NAME(obj, name)(PSYM(obj) this, type value)
// #define IVFNIMPL_NAME(obj, name) __objfunc$internal_##obj##$impl_virtual_##name          // Name of implementation for a virtual method
// #define IVPGIMPL_NAME(obj, name) __objfunc$internal_##obj##$impl_virtual_##name##$getter // Name of implementation for a virtual property
// getter #define IVPSIMPL_NAME(obj, name) __objfunc$internal_##obj##$impl_virtual_##name##$setter // Name of implementation for a virtual
// property setter
// #define IVFNIMPL(obj, type, name, ...) \
//     static type IVFNIMPL_NAME(obj, name)(PISYM(obj) this, ##__VA_ARGS__)                // Implementation for internal virtual member
//     function
// #define IVPGIMPL(obj, type, name) static type IVPGIMPL_NAME(obj, name)(PISYM(obj) this) // Implementation for internal virtual property
// getter
// #define IVPSIMPL(obj, type, name) \
//     static void IVPSIMPL_NAME(obj, name)(PISYM(obj) this, type value) // Implementation for internal virtual property setter

#define __OBJCTOR_NAME(x) __objfunc_##x##$__ctor             // Name of object constructor
#define OBJCTOR_NAME(x) __OBJCTOR_NAME(x)                    // Name of object constructor
#define __OBJDTOR_NAME(x) __objfunc_##x##$__dtor             // Name of object destructor
#define OBJDTOR_NAME(x) __OBJDTOR_NAME(x)                    // Name of object destructor
#define OBJCTOR(x, ...) PSYM(x) OBJCTOR_NAME(x)(__VA_ARGS__) // Object constructor
#define OBJDTOR(x) static void OBJDTOR_NAME(x)(x __this)     // Object destructor

#define DTOR OBJDTOR(SCOPE_SYMNAME)
#define DTOR_NAME(x) OBJDTOR_NAME(x)
#define CTOR OBJCTOR(SCOPE_SYMNAME)
#define CTOREX(tag, ...) OBJCTOREX(SCOPE_SYMNAME, tag, ##__VA_ARGS__)

// #define OBJ_USEVFNIMPL(sym, obj, fname) ((PSYM(sym))(obj))->fname = VFNIMPL_NAME(sym, fname)
// #define OBJBASE_USEVFNIMPL(sym, obj, fname) (obj)->Base.fname = VFNIMPL_NAME(sym, fname)
// #define IOBJ_USEVFNIMPL(sym, obj, fname) (obj)->fname = IVFNIMPL_NAME(sym, fname)
// #define IOBJBASE_USEVFNIMPL(sym, obj, fname) (obj)->Base.fname = IVFNIMPL_NAME(sym, fname)
// #define OBJ_USEVPGIMPL(sym, obj, prop) ((PSYM(sym))(obj))->PROPG_NAME(prop) = VPGIMPL_NAME(sym, prop)
// #define OBJBASE_USEVPGIMPL(sym, obj, prop) (obj)->Base.PROPG_NAME(prop) = VPGIMPL_NAME(sym, prop)
// #define IOBJ_USEVPGIMPL(sym, obj, prop) (obj)->PROPG_NAME(prop) = IVPGIMPL_NAME(sym, prop)
// #define IOBJBASE_USEVPGIMPL(sym, obj, prop) (obj)->Base.PROPG_NAME(prop) = IVPGIMPL_NAME(sym, prop)
// #define OBJ_USEVPSIMPL(sym, obj, prop) ((PSYM(sym))(obj))->PROPS_NAME(prop) = VPSIMPL_NAME(sym, prop)
// #define OBJBASE_USEVPSIMPL(sym, obj, prop) (obj)->Base.PROPS_NAME(prop) = VPSIMPL_NAME(sym, prop)
// #define IOBJ_USEVPSIMPL(sym, obj, prop) (obj)->PROPS_NAME(prop) = IVPSIMPL_NAME(sym, prop)
// #define IOBJBASE_USEVPSIMPL(sym, obj, prop) (obj)->Base.PROPS_NAME(prop) = IVPSIMPL_NAME(sym, prop)
// #define OBJ_USEDTOR(x, obj) ((POBJECT)obj)->$dtor = OBJDTOR_NAME(x);
// #define OBJ_USEDTOREX(x, tag, obj) ((POBJECT)obj)->$dtor = OBJDTOREX_NAME(x, tag);

#define NEW(type, ...) OBJCTOR_NAME(type)(__VA_ARGS__)               // Create object
#define NEWEX(type, tag, ...) OBJCTOREX_NAME(type, tag)(__VA_ARGS__) // Create object (extended)
#define DEL(obj) $(OBJECT, obj, $__special_dtor)                     // Delete object

#define OBJALLOC(x) __platform_AllocateMemory(sizeof(SYM(x)), SYMID_CONST_NAME(x))
#define OBJFREE(x, type) __platform_DeallocateMemory(x, SYMID_CONST_NAME(type))
#define CREATEINSTANCE                                                                                                                         \
    void* __this = OBJALLOC(SCOPE_SYMNAME);                                                                                                    \
    this->__vtable = &VTABLECONSTNAME(SCOPE_SYMNAME);
#define CREATEINSTANCE_NAMED(name)                                                                                                             \
    void* name = OBJALLOC(SCOPE_SYMNAME);                                                                                                      \
    T(name)->__vtable = &VTABLECONSTNAME(SCOPE_SYMNAME);
#define DESTROYINSTANCE OBJFREE(__this, SCOPE_SYMNAME)

#define $get(obj, prop) ((*((obj)->PROPG_NAME(prop)))((obj)))                          // Getter call
#define $set(obj, prop, value) ((*((obj)->PROPS_NAME(prop)))((obj), value))            // Setter call
#define $(type, obj, member, ...) (OBJMEMBER_NAME(type, member)((obj), ##__VA_ARGS__)) // Member call
#define $$(type, func, ...) (OBJMEMBER_STATIC_NAME(type, func)(__VA_ARGS__))

#define _$(obj, member, ...) $(SCOPE_SYMNAME, obj, member, ##__VA_ARGS__) // Member call (internal)

#define META_TYPEID_UNDEFINED 0

#define THIS_ARG SCOPE_SYMNAME __this

#endif
