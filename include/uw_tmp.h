#ifndef __UW_TMP_H__
#define __UW_TMP_H__

# include "config.h"

# include <sys/types.h>

# ifdef HAS_UTMP_H

#  include <utmp.h>
#  ifdef _PATH_UTMP
#   define UW_TMP_UFILE _PATH_UTMP
#   define UW_TMP_WFILE _PATH_WTMP
#  elif defined(UTMP_FILE) /* AIX only has UTMP_FILE */
#   define UW_TMP_UFILE UTMP_FILE
#   define UW_TMP_WFILE WTMP_FILE
#  else
#   error neither _PATH_UTMP nor UTMP_FILE defined.
#  endif
typedef struct utmp uw_tmp;

# elif defined(HAS_UTMPX_H)

#  include <utmpx.h>
#  define UW_TMP_UFILE _UTMPX_FILE
#  define UW_TMP_WFILE _WTMPX_FILE

#  ifndef ut_time
#   define ut_time ut_tv.tv_sec
#  endif

typedef struct futmpx uw_tmp;
# else
#  error Could not locate either system header utmp.h or utmpx.h
# endif

#endif /* __UW_TMP_H__ */
