#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include "bool.h"

# ifdef __cplusplus
extern "C" {
# endif

typedef enum {
  LOG_DEBUG,
  LOG_VERBOSE,
  LOG_INFO,
  LOG_ANOMALY,
  LOG_WARNING,
  LOG_ERROR,
  LOG_FATAL
} log_level_t;

extern log_level_t log_level;

bool has_log_dest(FILE *f);
bool add_log_dest(FILE *f);
bool remove_log_dest(FILE *f);
FILE * list_log_dests(void);
void log(log_level_t severity, const char * fmt, ...);

# define debug(x...)   (log(LOG_DEBUG, x, ...))
# define verbose(x...) (log(LOG_VERBOSE, x, ...))
# define info(x...)    (log(LOG_INFO, x, ...))
# define warning(x...) (log(LOG_WARNING, x, ...))
# define error(x...)   (log(LOG_ERROR, x, ...))
# define fatal(x...)   (log(LOG_FATAL, x, ...))

# define anomaly(cond) (if (!(cond)) log(LOG_ANOMALY, "%s:%d  anomaly check failed: %s", __FILE__, __LINE__, ##cond))

# ifdef __cplusplus
}
# endif
#endif /* __LOG_H__ */
