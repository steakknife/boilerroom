#ifndef __INT16_H__
#define __INT16_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef int16_t int16;
# elif HAS_16BIT_LL
typedef long long int16;
# elif HAS_16BIT_L
typedef long int16;
# elif HAS_16BIT_I
typedef int int16;
# elif HAS_16BIT_S
typedef short int16;
# else
#  error "No 16-bit type detected"
# endif

#endif /* __UINT16_H__ */
