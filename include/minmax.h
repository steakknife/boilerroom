#ifndef __MINMAX_H__
#define __MINMAX_H__

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define CLIP_TO_INCL(x, a, b) (MIN(MAX((x), (a)), (b)))
#define CLIP_TO_EXCL(x, a, b) (CLIP_TO_INCL((x), ((a)+1), ((b)-1)))

#define IN_RANGE_INCL(x, a, b) ((x) >= (a) && (x) <= (b))
#define IN_RANGE_EXCL(x, a, b) ((x) > (a) && (x) < (b))

#endif /* __MINMAX_H__ */
