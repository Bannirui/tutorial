#include <stdio.h>

#include "adder.h"

int main(int argc, char **argv)
{
  int a = 1;
  int b = 4;
  printf("测试adder\n%d+%d=%d\n", a, b, add(a, b));
  return 0;
}