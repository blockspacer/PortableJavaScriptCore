// billming
// basically replacement for wtf/platform.h
#ifndef GLOBAL_PLATFORM_H
#define GLOBAL_PLATFORM_H

#include <global_Compiler.h>
#include <global_Features.h>

#define PLATFORM(WTF_FEATURE) (defined WTF_PLATFORM_##WTF_FEATURE  && WTF_PLATFORM_##WTF_FEATURE)
#define CPU(WTF_FEATURE) (defined WTF_CPU_##WTF_FEATURE  && WTF_CPU_##WTF_FEATURE)
#define HAVE(WTF_FEATURE) (defined HAVE_##WTF_FEATURE  && HAVE_##WTF_FEATURE)
#define OS(WTF_FEATURE) (defined WTF_OS_##WTF_FEATURE  && WTF_OS_##WTF_FEATURE)
#define USE(WTF_FEATURE) (defined USE_##WTF_FEATURE  && USE_##WTF_FEATURE)
#define ENABLE(WTF_FEATURE) (defined ENABLE_##WTF_FEATURE  && ENABLE_##WTF_FEATURE)

// POSIX
#define WTF_OS_UNIX 1
#define USE_PTHREADS 1
//#define HAVE_SYS_TIME_H 1
// On Windows, its provided by pthread lib.
#define HAVE_LOCALTIME_R 1
#define HAVE_STRINGS_H 1

// JSVALUE64 for 64bit platforms, otherwise, use JSVALUE32_64
#define USE_JSVALUE64 1
#define USE_JSVALUE32_64 0
// this way CLoop will be friend of many classes.
#define LLIntOffsetsExtractor CLoop

// May set this to 1 for gcc and clang
#define HAVE_COMPUTED_GOTO 0

// JIT should be disabled
#define JIT_OPERATION

#define USE_SYSTEM_MALLOC 1

#define USE_GENERIC_EVENT_LOOP 1

#endif // GLOBAL_PLATFORM_H
