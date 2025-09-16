#include "FileStream.h"
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SCOPE_SYMNAME FILESTREAM

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
MEMBER_VIRTUAL(bool, IsReadable) {}

#undef SCOPE_SYMNAME