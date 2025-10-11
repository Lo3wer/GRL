#pragma once

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #define GRL_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define GRL_PLATFORM_LINUX
#elif defined(__APPLE__)
    #define GRL_PLATFORM_MACOS
#endif

// Compiler detection
#if defined(_MSC_VER)
    #define GRL_COMPILER_MSVC
#elif defined(__GNUC__)
    #define GRL_COMPILER_GCC
#elif defined(__clang__)
    #define GRL_COMPILER_CLANG
#endif

// Debug/Release
#if defined(_DEBUG) || !defined(NDEBUG)
    #define GRL_DEBUG
#else
    #define GRL_RELEASE
#endif

// Assertions
#ifdef GRL_DEBUG
    #include <cassert>
    #define GRL_ASSERT(condition, message) assert((condition) && (message))
#else
    #define GRL_ASSERT(condition, message)
#endif
