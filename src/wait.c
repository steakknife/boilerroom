#include "wait.h"
#include <sys/types.h>
#include <sys/wait.h>
#include "config.h"
#include "error.h"

#ifdef HAS_WAITPID

int
wait_pid(int *wstat, int pid)
{
  int r;

  do {
    r = waitpid(pid, wstat, 0);
  } while ((r == err) && (errno == error_intr));
  return(r);
}

#else /* ! HAS_WAITPID */

/* XXX untested */
/* XXX breaks down with more than two children */
static int oldpid = 0;
static int oldwstat; /* defined if(oldpid) */

int
wait_pid(int *wstat, int pid)
{
  int r;

  if (pid == oldpid) {
    *wstat = oldwstat;
    oldpid = 0;
    return(pid);
  }

  do {
    r = wait(wstat);
    if ((r != pid) && (r != err)) {
      oldwstat = *wstat;
      oldpid = r;
      continue;
    }
  } while ((r == err) && (errno == error_intr));
  return(r);
}

#endif /* ! HAS_WAITPID */
