#pragma once

#ifndef __PLATFORM_H__HEADERGUARD__
#define __PLATFORM_H__HEADERGUARD__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef WIN32
// #include <Windows.h>
HANDLE ConsoleInput;
HANDLE ConsoleOutput;
#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define FOREGROUND_CYAN (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_MAGENTA (FOREGROUND_BLUE | FOREGROUND_RED)
#define FOREGROUND_YELLOW (FOREGROUND_GREEN | FOREGROUND_RED)
#define BACKGROUND_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define BACKGROUND_CYAN (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BACKGROUND_MAGENTA (BACKGROUND_BLUE | BACKGROUND_RED)
#define BACKGROUND_YELLOW (BACKGROUND_GREEN | BACKGROUND_RED)
#endif

bool ClearConsole();

// #define OBJALLOC(sym, id)                                                                                                                      \
//     P##sym this = __platform_AllocateMemory(sizeof(sym), id);                                                                                  \
//     if (!this) return NULL
// #define OBJFREE(obj, id) __platform_DeallocateMemory(obj, id)

void* __platform_AllocateMemory(size_t, unsigned);
bool __platform_DeallocateMemory(void*, unsigned);

#endif
