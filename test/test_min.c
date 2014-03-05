#include "minmax.h"

int
main(void)
{
  return(!(
    (MIN(1, 3) == 1) &&
    (MIN(9, 7) == 7) &&
    (MIN(0, 0) == 0) &&
    (MIN(10, 0) == 0) &&
    (MIN(0, 10) == 0)
  ));
}
