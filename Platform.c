#include "Platform.h"
#include <stdbool.h>
#include <stddef.h>

#ifdef WIN32
// #include <Windows.h>
bool ClearConsole() { // Pure Windows way
    CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo = {0};
    if (!GetConsoleScreenBufferInfo(ConsoleOutput, &consoleBufferInfo)) { // Get the size of the Console Buffer.
        return false;
    }

    DWORD cells = consoleBufferInfo.dwSize.X * consoleBufferInfo.dwSize.Y;
    COORD origin = {0, 0}; // The (0, 0) position.
    DWORD tmp;             // Used to temporarily retrieve the count of written characters.
    if (!FillConsoleOutputCharacterW(ConsoleOutput, L'\0', cells, origin, &tmp)) { // Clear characters.
        return false;
    }
    if (!FillConsoleOutputAttribute(ConsoleOutput, consoleBufferInfo.wAttributes, cells, origin, &tmp)) { // Clear attributes.
        return false;
    }
    if (!SetConsoleCursorPosition(ConsoleOutput, origin)) { // Reset cursor position.
        return false;
    }

    return true;
}

void* __platform_AllocateMemory(size_t size, uint32_t typeId) {
    void* allocated = LocalAlloc(LMEM_ZEROINIT, size + 4);
    if (allocated == NULL) {
        return NULL;
    }
    *((uint32_t*)allocated) = typeId;
    return (void*)((char*)allocated + 4);
}
bool __platform_DeallocateMemory(void* obj, uint32_t typeId) {
    void* ptr = (void*)((char*)obj - 4);
    if (obj != NULL && *((uint32_t*)ptr) == typeId) {
        LocalFree(ptr);
        return true;
    }
    return false;
}
#endif

#ifdef __linux__
// #include <sys/mman.h>
#include <stdlib.h>

bool ClearConsole() {
    putchar('\033');
    puthcar('c');
    return true;
}

void* __platform_AllocateMemory(size_t size, uint32_t typeId) {
    void* allocated = malloc(size + 4);
    if (allocated == NULL) {
        return NULL;
    }
    *((uint32_t*)allocated) = typeId;
    return (void*)((char*)allocated + 4);
}
bool __platform_DeallocateMemory(void* obj, uint32_t typeId) {
    void* ptr = (void*)((char*)obj - 4);
    if (obj != NULL && *((uint32_t*)ptr) == typeId) {
        free(ptr);
        return true;
    }
    return false;
}
#endif