#include "log.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

log_level_t log_level = LOG_ANOMALY;

static FILE **log_dests = NULL;

static FILE**
alloc_log_dests(int count)
{
  return((FILE**)malloc(sizeof(FILE**) * (count + 1)));
}

static void
dealloc_log_dests(FILE** *x)
{
  if (x && *x) {
    free(*x);
    *x = NULL;
  }
}

static FILE**
new_log_dests(FILE *initial)
{
  log_dests = alloc_log_dests(1);
  if (log_dests) {
    log_dests[0] = initial;
    log_dests[1] = NULL;
  }
  return(log_dests);
}

static FILE**
default_log_dests(void)
{
  return(new_log_dests(stderr));
}

static size_t
count_log_dests(void)
{
  size_t result = 0;
  if (log_dests) {
    for (FILE** walk = log_dests; (*walk); ++walk) {
      ++result;
    }
  }
  return(result);
}

static FILE**
append_log_dest(FILE *f)
{
  size_t count = count_log_dests();
  FILE** bigger_log_dests = alloc_log_dests(count+1);
  if (!bigger_log_dests) return(NULL);

  memcpy(bigger_log_dests, log_dests, sizeof(FILE**)*count);
  bigger_log_dests[count-1] = f;
  bigger_log_dests[count] = NULL;
  FILE **old_dests = log_dests;
  log_dests = bigger_log_dests;
  dealloc_log_dests(&old_dests);

  return(log_dests);
}

static int
index_log_dest(FILE *f)
{
  if (!f) return(-1);
  if (!log_dests) return(-1);
  size_t index = 0;
  for (FILE **walk = log_dests; (*walk); ++walk, ++index) {
    if (*walk == f) return(index);
  }
  return(-1);
}


/*
 *
 *
 *              x
 *      0 1 2 3 4 5 6 7 8 9
 *      0 1 2 3 5 6 7 8 9
 *
 */
static FILE**
shrink_log_dest(FILE *f)
{
  int index_to_remove = index_log_dest(f);
  size_t count = count_log_dests();
  FILE** smaller_log_dests = alloc_log_dests(count-1);
  if (!smaller_log_dests) return(NULL);
  if (index_to_remove > 0)
    memcpy(smaller_log_dests, log_dests, (index_to_remove-1)*sizeof(FILE*)); 
  if (index_to_remove < count-1)
    memcpy(&smaller_log_dests[index_to_remove], &log_dests[index_to_remove+1], ((count - index_to_remove + 1) - 1)*sizeof(FILE*)); 
  FILE **old_dests = log_dests;
  log_dests = smaller_log_dests;
  dealloc_log_dests(&old_dests);
  return(log_dests);
}

bool
has_log_dest(FILE *f)
{
  return(index_log_dest(f) >= 0);
}

bool
add_log_dest(FILE *f)
{
  if (!f) return(false);
  if (has_log_dest(f)) return(true);
  if (!log_dests) {
    if (new_log_dests(f)) return(true);
  } else {
    if (append_log_dest(f)) return(true);
  }
  return(false);
}

bool
remove_log_dest(FILE *f)
{
  if (!f) return(false);
  if (!has_log_dest(f)) return(true);
  return((shrink_log_dest(f)) ? true : false);
}

void
log(log_level_t severity, const char * fmt, ...)
{
  if (severity < log_level) return;
  va_list args;
  va_start(args, fmt);
  if (!log_dests) default_log_dests();
  for (FILE **walk = log_dests; (*walk); ++walk) {
    vfprintf(*walk, fmt, args);
  } 
  va_end(args);
}

