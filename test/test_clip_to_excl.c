#include "minmax.h"

int
main(void)
{
  return(!(
    (CLIP_TO_EXCL(0,  1, 3) == 2) &&
    (CLIP_TO_EXCL(1,  1, 3) == 2) &&
    (CLIP_TO_EXCL(2,  1, 3) == 2) &&
    (CLIP_TO_EXCL(3,  1, 3) == 2) &&
    (CLIP_TO_EXCL(4,  1, 3) == 2) &&
    (CLIP_TO_EXCL(5,  1, 3) == 2) &&

    (CLIP_TO_EXCL(0,  1, 4) == 2) &&
    (CLIP_TO_EXCL(1,  1, 4) == 2) &&
    (CLIP_TO_EXCL(2,  1, 4) == 2) &&
    (CLIP_TO_EXCL(3,  1, 4) == 3) &&
    (CLIP_TO_EXCL(4,  1, 4) == 3) &&
    (CLIP_TO_EXCL(5,  1, 4) == 3)
  ));
}
