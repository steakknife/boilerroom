#include <stdio.h>
#include "zero.h"

#define BUF_SZ 4096
#define BUF_PART_SZ 13
#define MAGIC 0xFE

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
typedef struct {
  int i;
  int j;
  double d;
  int k;
} example;
#pragma clang diagnostic pop

int test0(void);
int test1(void);

int
test0(void)
{
  example x = { 1, 2, 1.0, 1 };
  zero(x, sizeof(x));
  return(x.i == 0 && x.j == 0 && x.d == 0.0 && x.k == 0);
}

int
test1(void)
{
  unsigned char buf[BUF_SZ];
  memset(buf, MAGIC, BUF_SZ);
  zero(buf, BUF_PART_SZ);
  return(buf[0] == 0 &&
      buf[BUF_PART_SZ - 1] == 0 &&
      buf[BUF_PART_SZ] == MAGIC &&
      buf[BUF_SZ - 1] == MAGIC);
}

int
main(void)
{
  return ((test0() && test1()) ? 0 : 1);
}
