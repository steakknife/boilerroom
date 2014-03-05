#include <time.h>

int
main(void)
{
  nanosleep((struct timespec []){{0, 1}}, NULL);
  return(0);
}
