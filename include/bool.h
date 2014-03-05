#ifndef __BOOL_H__
#define __BOOL_H__

# ifdef __cplusplus
#  error "bool is already a C++ type"
/* bool is already a type */
# else /* ! __cplusplus */
#  include "config.h"
#  ifdef HAS_STDBOOL_H
#   include <stdbool.h>
#  endif /* HAS_BOOL_H */
#  ifdef __bool_true_false_are_defined
#   undef true
#   undef false
#   undef bool
#  endif /* __bool_true_false_are_defined */

/* typedef so that questionable coercions are obvious */
typedef enum {
  false = 0,
  true = 1,
} bool;

# endif /* ! __cplusplus */

#endif /* __BOOL_H__ */
