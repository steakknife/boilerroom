#ifndef __FD_H__
#define __FD_H__

#include "bool.h"

# ifdef __cplusplus
extern "C" {
# endif

bool fd_copy(int to, int from);
bool fd_move(int to, int from);

# ifdef __cplusplus
}
# endif

#endif /* __FD_H__ */
