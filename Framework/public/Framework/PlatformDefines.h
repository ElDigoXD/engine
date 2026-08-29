#pragma once

#if defined(TT_CLANG) || defined(TT_GCC)
#define TT_FORCEINLINE __attribute__((always_inline))
#elif defined(TT_MSVC)
#define TT_FORCEINLINE __forceinline
#endif
