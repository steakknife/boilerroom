#include "fd.h"
#include <unistd.h>
#include <fcntl.h>
#include "result.h"

bool
fd_copy(int to, int from)
{
  if (to == from) return(true);
  if (fcntl(from, F_GETFL, 0) == err) return(false);
  close(to);
  if (fcntl(from, F_DUPFD, to) == err) return(false);
  return(true);
}

bool
fd_move(int to, int from)
{
  if (to == from) return(true);
  if (!fd_copy(to, from)) return(false);
  close(from);
  return(true);
}
