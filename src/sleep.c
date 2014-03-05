#include "sleep.h"
#include "config.h"

# ifdef HAS_NANOSLEEP
#  include <time.h>
# else
#  include <unistd.h>
# endif

#define BILLION (1000000000L)

bool
sleepfrac(double x)
{
  int result;
#ifdef HAS_NANOSLEEP
  time_t wholeseconds = (time_t)(x);
  result = nanosleep((struct timespec []){{
      wholeseconds,
      (long)((x - wholeseconds)*BILLION)
    }}, NULL);
#else
  result = sleep((unsigned)(x));
#endif
  return((result == 0) ? true : false);
}

void
sleepfully(double x)
{
  int result;
  time_t wholeseconds = (time_t)(x);
#ifdef HAS_NANOSLEEP
  struct timespec requested = { wholeseconds,
                                (long)((x - wholeseconds)*BILLION) };
  struct timespec remaining;
        requested.tv_sec = wholeseconds,
  for (;;) {
    if (nanosleep(&requested, &remaining) == 0) break;
    memcpy(&requested, &remaining, sizeof(requested));
  }
#else
  for (result = wholeseconds; (result); ) {
    result = sleep(result);
  }
#endif
}
