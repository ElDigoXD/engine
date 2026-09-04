#pragma once

#if defined(__clang__) // Clang
#define TT_CLANG
#elif defined(__GNUC__)
#define TT_GCC
#elif defined(_MSC_VER)
#define TT_MSVC
#elif defined(__INTEL_COMPILER)
#define TT_INTEL
#endif

#if defined(TT_CLANG) || defined(TT_GCC)
#define TT_FORCEINLINE __attribute__((always_inline))
#elif defined(TT_MSVC)
#define TT_FORCEINLINE __forceinline
#endif
