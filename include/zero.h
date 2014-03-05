#ifndef __ZERO_H__
#define __ZERO_H__

# include <string.h>

# define zero(x, size) (memset(&(x), 0, (size)))
# define zero_var(x) (zero((x), sizeof(x)))
# define zero_array(x) (zero((x), sizeof(x) * sizeof(*(x))))

#endif /* __ZERO_H__ */
