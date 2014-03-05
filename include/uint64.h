#ifndef __UINT64_H__
#define __UINT64_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef uint64_t uint64;
# elif HAS_64BIT_ULL
typedef unsigned long long uint64;
# elif HAS_64BIT_UL
typedef unsigned long uint64;
# elif HAS_64BIT_U
typedef unsigned uint64;
# elif HAS_64BIT_US
typedef unsigned short uint64;
# else
#  error "No 64-bit type detected"
# endif

#endif /* __UINT64_H__ */
