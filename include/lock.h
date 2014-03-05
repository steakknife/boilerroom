#ifndef __LOCK_H__
#define __LOCK_H__

# include "config.h"

# ifdef HAS_FLOCK
#  include <sys/file.h>
#  define lock_ex(fd) (flock((fd), LOCK_EX))
#  define lock_exnb(fd) (flock((fd), LOCK_EX | LOCK_NB))
#  define lock_un(fd) (flock((fd), LOCK_UN))
# elif defined(HAS_LOCKF)
#  include <unistd.h>
#  define lock_ex(fd) (lockf((fd), 1 /* F_LOCK */, 0 /* size */))
#  define lock_exnb(fd) (lockf((fd), 2 /* F_TLOCK */, 0 /* size */))
#  define lock_un(fd) (lockf((fd), 0 /* F_UNLOCK */, 0 /* size */))
# else
#  error Neither flock() nor lockf() file locking mechanism detected
# endif

#endif /* __LOCK_H__ */
