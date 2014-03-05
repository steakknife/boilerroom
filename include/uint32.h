#ifndef __UINT32_H__
#define __UINT32_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef uint32_t uint32;
# elif HAS_32BIT_ULL
typedef unsigned long long uint32;
# elif HAS_32BIT_UL
typedef unsigned long uint32;
# elif HAS_32BIT_U
typedef unsigned uint32;
# elif HAS_32BIT_US
typedef unsigned short uint32;
# else
#  error "No 32-bit type detected"
# endif

#endif /* __UINT32_H__ */
