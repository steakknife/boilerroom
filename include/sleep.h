#ifndef __SLEEP_H__
#define __SLEEP_H__

# include "bool.h"

# ifdef __cplusplus
extern "C" {
# endif

bool sleepfrac(double seconds); /* false if sleep interrupted or failed */
void sleepfully(double seconds);

# ifdef __cplusplus
}
# endif

#endif /* __SLEEP_H__ */
