#include "Stream.h"

#define SCOPE_SYMNAME STREAM

VTABLEDEF{};

MEMBER(bool, IsReadable) { WRAP_VIRTUAL_CALL(bool, IsReadable); }
MEMBER(bool, IsWritable) { WRAP_VIRTUAL_CALL(bool, IsWritable); }
MEMBER(bool, IsSeekable) { WRAP_VIRTUAL_CALL(bool, IsSeekable); }
MEMBER(bool, IsEndOfStream) { WRAP_VIRTUAL_CALL(bool, IsEndOfStream); }
MEMBER(byte, Read) { WRAP_VIRTUAL_CALL(byte, Read); }
MEMBER(void, Write, byte data) { WRAP_VIRTUAL_CALL(void, Write, data); }
MEMBER(void, Seek, size_t pos, unsigned seekMode) { WRAP_VIRTUAL_CALL(void, Seek, pos, seekMode); }

#undef SCOPE_SYMNAME