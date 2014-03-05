#ifndef __UINT8_H__
#define __UINT8_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef uint8_t uint8;
# elif HAS_8BIT_UC
typedef unsigned char uint8;
# else
#  error "No 8-bit type detected"
# endif

#endif /* __UINT8_H__ */
