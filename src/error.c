#include "error.h"

/* warning: as coverage improves here, should update error_{str,temp} */

const int error_intr =
#ifdef EINTR
EINTR;
#else
-1;
#endif

const int error_nomem =
#ifdef ENOMEM
ENOMEM;
#else
-2;
#endif

const int error_noent = 
#ifdef ENOENT
ENOENT;
#else
-3;
#endif

const int error_txtbsy =
#ifdef ETXTBSY
ETXTBSY;
#else
-4;
#endif

const int error_io =
#ifdef EIO
EIO;
#else
-5;
#endif

const int error_exist =
#ifdef EEXIST
EEXIST;
#else
-6;
#endif

const int error_timeout =
#ifdef ETIMEDOUT
ETIMEDOUT;
#else
-7;
#endif

const int error_inprogress =
#ifdef EINPROGRESS
EINPROGRESS;
#else
-8;
#endif

const int error_wouldblock =
#ifdef EWOULDBLOCK
EWOULDBLOCK;
#else
-9;
#endif

const int error_again =
#ifdef EAGAIN
EAGAIN;
#else
-10;
#endif

const int error_pipe =
#ifdef EPIPE
EPIPE;
#else
-11;
#endif

const int error_perm =
#ifdef EPERM
EPERM;
#else
-12;
#endif

const int error_acces =
#ifdef EACCES
EACCES;
#else
-13;
#endif

const int error_nodevice =
#ifdef ENXIO
ENXIO;
#else
-14;
#endif

const int error_proto =
#ifdef EPROTO
EPROTO;
#else
-15;
#endif

const int error_isdir =
#ifdef EISDIR
EISDIR;
#else
-16;
#endif

const int error_connrefused =
#ifdef ECONNREFUSED
ECONNREFUSED;
#else
-17;
#endif

const int error_notdir =
#ifdef ENOTDIR
ENOTDIR;
#else
-18;
#endif

