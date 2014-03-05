#ifndef __INT8_H__
#define __INT8_H__

# include "config.h"

# ifdef HAS_INTTYPES_H
#  include <inttypes.h>
typedef int8_t int8;
# elif HAS_8BIT_SC
typedef signed char int8;
# else
#  error "No 8-bit type detected"
# endif

#endif /* __INT8_H__ */
