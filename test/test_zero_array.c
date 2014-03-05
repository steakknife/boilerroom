#include "zero.h"

#define BUF_SZ (256*1024)
#define MAGIC (0xA5)

int
main(void)
{
  char buf[BUF_SZ];
  memset(buf, MAGIC, BUF_SZ);
  zero_array(buf);
  return((memchr(buf, MAGIC, BUF_SZ) == NULL) ? 0 : 1);
}
