#include <String.h>
#include <ctype.h>

#define SCOPE_SYMNAME STRING

#define BUF(x) (T(x)->Buffer)
#define LEN(x) (T(x)->Length)
#define MEM(x) (T(x)->Memory)

META_ID = 9;

DTOR {
    $(BYREFMEMORY, MEM(this), DecreaseReference);
    DESTROYINSTANCE;
}

VTABLEDEF{VTDEF_DTOR};

MEMBER(wchar_t, At, size_t pos) { return BUF(this)[pos]; }

MEMBER_PROPG(size_t, Length) { return LEN(this); }

MEMBER_STATIC(STRING, FromBuffer, const wchar_t* buffer) {
    CREATEINSTANCE;
    size_t count = wcslen(buffer);
    BYREFMEMORY memory = $$(BYREFMEMORY, Create, count + 1);
    wchar_t* nbuf = $(BYREFMEMORY, memory, GetAllocation);
    wcscpy(nbuf, buffer);
    BUF(this) = nbuf;
    MEM(this) = memory;
    LEN(this) = count;
    return this;
}

MEMBER(int, CompareTo, STRING that) {
    size_t min = LEN(this) < LEN(that) ? LEN(this) : LEN(that);
    for (size_t i = 0; i < min; i++) {
        if (BUF(this)[i] < BUF(that)[i]) {
            return -1;
        } else if (BUF(this)[i] > BUF(that)[i]) {
            return 1;
        }
    }
    return LEN(this) < LEN(that) ? -1 : LEN(this) > LEN(that) ? 1 : 0;
}

MEMBER(STRING, Substring, size_t offset, size_t count) {
    CREATEINSTANCE_NAMED(result);
    $(BYREFMEMORY, MEM(result), IncreaseReference);
    LEN(result) = count;
    MEM(result) = MEM(this);
    BUF(result) = BUF(this) + offset;
}

MEMBER(STRING, TrimStart) {
    size_t begin = 0;
    while (begin < LEN(this) && isspace(BUF(this)[begin])) {
        begin++;
    }

    return _$(this, Substring, begin, LEN(this) - begin);
}

MEMBER(STRING, TrimEnd) {
    size_t len = LEN(this);
    while (len > 0 && isspace(BUF(this)[len - 1])) {
        len--;
    }
    return _$(this, Substring, 0, len);
}

MEMBER(STRING, Trim) {
    size_t begin = 0, end = LEN(this);
    while (begin < end && isspace(BUF(this)[begin])) {
        begin++;
    }
    while (end > begin && isspace(BUF(this)[end - 1])) {
        end--;
    }
    return _$(this, Substring, begin, end - begin);
}

MEMBER_STATIC(bool, IsNullOrEmpty, STRING str) { return str == NULL || LEN(str) == 0; }

#undef SCOPE_SYMNAME