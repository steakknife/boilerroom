#ifndef __UINT16_H__
#define __UINT16_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef uint16_t uint16;
# elif HAS_16BIT_ULL
typedef unsigned long long uint16;
# elif HAS_16BIT_UL
typedef unsigned long uint16;
# elif HAS_16BIT_U
typedef unsigned uint16;
# elif HAS_16BIT_US
typedef unsigned short uint16;
# else
#  error "No 16-bit type detected"
# endif

#endif /* __UINT16_H__ */
