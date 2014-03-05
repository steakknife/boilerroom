#include "minmax.h"

int
main(void)
{
  return(!(
    (CLIP_TO_INCL(0,  1, 3) == 1) &&
    (CLIP_TO_INCL(1,  1, 3) == 1) &&
    (CLIP_TO_INCL(2,  1, 3) == 2) &&
    (CLIP_TO_INCL(3,  1, 3) == 3) &&
    (CLIP_TO_INCL(4,  1, 3) == 3) &&
    (CLIP_TO_INCL(5,  1, 3) == 3)
  ));
}
