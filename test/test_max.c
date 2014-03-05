#include "minmax.h"

int
main(void)
{
  return(!(
    (MAX(1, 3) == 3) &&
    (MAX(9, 7) == 9) &&
    (MAX(0, 0) == 0) &&
    (MAX(10, 0) == 10) &&
    (MAX(0, 10) == 10)
  ));
}
