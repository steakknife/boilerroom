#ifndef __INT32_H__
#define __INT32_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef int32_t int32;
# elif HAS_32BIT_LL
typedef long long int32;
# elif HAS_32BIT_L
typedef long int32;
# elif HAS_32BIT_I
typedef int int32;
# elif HAS_32BIT_S
typedef short int32;
# else
#  error "No 32-bit type detected"
# endif

#endif /* __INT32_H__ */
