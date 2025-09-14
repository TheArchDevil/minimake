#include "Base.h"
#include "Platform.h"
// #include <Windows.h>

#define SCOPE_SYMNAME OBJECT

DTOR { DESTROYINSTANCE; }

VTABLESYM { VTABLE_FUNC(OBJECT, void, $dtor); };
VTABLEDEF{VTDEF_DTOR};

#undef SCOPE_SYMNAME

// // STRING
// SYMID(STRING, 9);

// ISYM(STRING) {
//     INHERIT(STRING);
//     const wchar_t* data;
//     size_t length;
// };

// IVPGIMPL(STRING, size_t, Length) { return this->length; }
// IVFNIMPL(STRING, wchar_t, At, size_t index) { return this->data[index]; }
// IVFNIMPL(STRING, const wchar_t*, ToCharArray) { return this->data; }

// OBJDTOR(STRING) { OBJFREE(this, TYPEID(STRING)); }
// OBJCTOR(STRING, const wchar_t* data) {
//     OBJALLOC(ISYM(STRING), TYPEID(STRING));
//     OBJ_USEDTOR(STRING, this);
//     this->length = wcslen(data);
//     this->data = data;
//     this->Base.PROPG_NAME(Length) = IVPGIMPL_NAME(STRING, Length);
//     this->Base.ToCharArray = IVFNIMPL_NAME(STRING, ToCharArray);
//     this->Base.At = IVFNIMPL_NAME(STRING, At);
//     return this;
// }

// // VARSTRING
// SYMID(VARSTRING, 11);

// ISYM(VARSTRING) {
//     INHERIT(VARSTRING);
//     MEMFN(VARSTRING, void, Expand);
//     wchar_t* data;
//     size_t length;
//     size_t bufferLength;
// };

// IVPGIMPL(VARSTRING, size_t, Length) { return this->length; }
// IVFNIMPL(VARSTRING, void, Add, wchar_t ch) {
//     if (this->length >= this->bufferLength - 1) {
//         this->bufferLength *= 2;
//         wchar_t* tmp = malloc(this->bufferLength * sizeof(wchar_t));
//         if (tmp == NULL) {
//             return;
//         }
//         for (size_t i = 0; i < this->length; i++) {
//             tmp[i] = this->data[i];
//         }
//         free(this->data);
//         this->data = tmp;
//     }
//     this->data[this->length++] = ch;
// }
// IVFNIMPL(VARSTRING, void, InsertAt, size_t index, wchar_t ch) {
//     if (index > this->length) {
//         return;
//     }
//     if (this->length >= this->bufferLength - 1) {
//         _(this, Expand);
//     }
//     for (size_t i = this->length; i > index; i--) {
//         this->data[i] = this->data[i - 1];
//     }
//     this->data[index] = ch;
//     this->length++;
// }
// IVFNIMPL(VARSTRING, void, Expand) {
//     if (this->length >= this->bufferLength - 1) {
//         this->bufferLength *= 2;
//         wchar_t* tmp = malloc(this->bufferLength * sizeof(wchar_t));
//         if (tmp == NULL) {
//             return;
//         }
//         for (size_t i = 0; i < this->length; i++) {
//             tmp[i] = this->data[i];
//         }
//         free(this->data);
//         this->data = tmp;
//     }
// }
// IVFNIMPL(VARSTRING, wchar_t, Remove) {
//     if (this->length > 0) {
//         this->length--;
//         return this->data[this->length];
//     }
//     return -1;
// }
// IVFNIMPL(VARSTRING, wchar_t, RemoveAt, size_t index) {
//     if (this->length > index) {
//         this->length--;
//         wchar_t removed = this->data[index];
//         for (size_t i = index; i < this->length; i++) {
//             this->data[i] = this->data[i + 1];
//         }
//         return removed;
//     }
//     return -1;
// }
// IVFNIMPL(VARSTRING, wchar_t, At, size_t index) {
//     if (index < this->length) {
//         return this->data[index];
//     }
//     return -1;
// }
// OBJDTOREX(STRING, FrozenStringDestructor) {
//     free(_(this, ToCharArray));
//     OBJFREE(this, TYPEID(STRING));
// }
// IVFNIMPL(VARSTRING, PSTRING, Freeze) {
//     _(this, Base.Add, L'\0');
//     PSTRING frozen = NEW(STRING, this->data);
//     OBJ_USEDTOREX(STRING, FrozenStringDestructor, frozen);
//     OBJFREE(this, TYPEID(VARSTRING));
//     return frozen;
// }
// IVFNIMPL(VARSTRING, const wchar_t*, ToCharArray) {
//     _(this, Base.Add, L'\0');
//     _(this, Base.Remove);
//     return this->data;
// }
// IVFNIMPL(VARSTRING, void, Append, PSTRING str) {
//     for (size_t size = $(str, Length), i = 0; i < size; i++) {
//         _(this, Base.Append, _(str, At, i));
//     }
// }
// IVFNIMPL(VARSTRING, void, Clear) { this->length = 0; }

// OBJDTOR(VARSTRING) {
//     free(((PISYM(VARSTRING))this)->data);
//     OBJFREE(this, TYPEID(VARSTRING));
// }
// OBJCTOR(VARSTRING) {
//     OBJALLOC(ISYM(VARSTRING), TYPEID(VARSTRING));
//     OBJ_USEDTOR(VARSTRING, this);
//     IOBJBASE_USEVPGIMPL(VARSTRING, this, Length);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, Append);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, ToCharArray);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, Clear);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, Add);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, Remove);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, InsertAt);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, RemoveAt);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, At);
//     IOBJBASE_USEVFNIMPL(VARSTRING, this, Freeze);
//     IOBJ_USEVFNIMPL(VARSTRING, this, Expand);
//     this->data = malloc(sizeof(wchar_t));
//     this->bufferLength = 1;
//     this->length = 0;
//     return this;
// }
