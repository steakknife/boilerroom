#ifndef __INT64_H__
#define __INT64_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef int64_t int64;
# elif HAS_64BIT_LL
typedef long long uint64;
# elif HAS_64BIT_L
typedef long uint64;
# elif HAS_64BIT_I
typedef int uint64;
# elif HAS_64BIT_S
typedef short uint64;
# else
#  error "No 64-bit type detected"
# endif

#endif /* __INT64_H__ */
