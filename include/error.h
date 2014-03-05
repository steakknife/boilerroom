#ifndef __ERROR_H__
#define __ERROR_H__

# include "config.h"

# ifdef HAS_ERRNO_H
#  include <errno.h>
# endif /* HAS_ERRNO_H */

# ifdef __cplusplus
extern "C" {
# endif

const int error_intr;
const int error_nomem;
const int error_noent;
const int error_txtbsy;
const int error_io;
const int error_exist;
const int error_timeout;
const int error_inprogress;
const int error_wouldblock;
const int error_again;
const int error_pipe;
const int error_perm;
const int error_acces;
const int error_nodevice;
const int error_proto;
const int error_isdir;
const int error_connrefused;
const int error_notdir;

const char *error_str(int);
const int error_temp(int);

# ifdef __cplusplus
}
# endif

#endif /* __ERROR_H__ */
