#include "FileStream.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILESTREAM_BUFFER_HALFSIZE 32768

#define SCOPE_SYMNAME FILESTREAM

META_ID = 1073741856;

DTOR {
    __platform_DeallocateMemory(this->Buffer, META_TYPEID_UNDEFINED);
    if (!this->IsSharedFd) {
        close(this->fd);
    }
    DESTROYINSTANCE;
}
static bool __CheckFileDescriptorPermissions(int fd, int perm) {
    int flags = fcntl(fd, F_GETFL);
    int accmode = flags & O_ACCMODE;
    return (accmode & perm) == perm;
}

MEMBER_VIRTUAL(bool, IsReadable) { return __CheckFileDescriptorPermissions(this->fd, O_RDONLY); }
MEMBER_VIRTUAL(bool, IsWritable) { return __CheckFileDescriptorPermissions(this->fd, O_WRONLY); }
MEMBER_VIRTUAL(bool, IsSeekable) {
    struct stat s;
    fstat(this->fd, &s);
    return S_ISREG(s.st_mode);
}
MEMBER_VIRTUAL(byte, Read) {
    byte b;
    read(this->fd, &b, 1);
    return b;
}
MEMBER_VIRTUAL(void, Write, byte data) { write(this->fd, &data, 1); }
MEMBER_VIRTUAL(size_t, ReadBuffer, byte* buffer, size_t count) {
    ssize_t x = read(this->fd, buffer, count);
    if (x < 0) {
        return 0;
    }
    return x;
}
MEMBER_VIRTUAL(size_t, WriteBuffer, byte* buffer, size_t count) {
    ssize_t x = write(this->fd, buffer, count);
    if (x < 0) {
        return 0;
    }
    return x;
}
MEMBER_VIRTUAL(void, Seek, size_t pos, unsigned seekMode) { lseek(this->fd, pos, seekMode); }

VTABLEDEF{VTDEF_DTOR,        VTDEF_FUNC(IsReadable), VTDEF_FUNC(IsWritable),  VTDEF_FUNC(IsSeekable), VTDEF_FUNC(Read),
          VTDEF_FUNC(Write), VTDEF_FUNC(ReadBuffer), VTDEF_FUNC(WriteBuffer), VTDEF_FUNC(Seek)};

#undef SCOPE_SYMNAME