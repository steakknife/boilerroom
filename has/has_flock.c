#include <sys/file.h>
#include <stdio.h>

int
main(void)
{
  int result = flock(0, LOCK_EX);

  if (result)
    perror("flock(0, LOCK_EX)");
 
  return (result);
}
