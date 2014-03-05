#include "zero.h"

int
main(void)
{
  int i = -1;
  zero_var(i);
  return ((i == 0) ? 0 : 1);
}
