#include <stdio.h>

#include <TestConfig.h>

int main(int argc, char **argv)
{
  printf("测试configure_file自动生成的文件\nhello world\nVersion %d.%d\n", VERSION_MAJOR, VERSION_MINOR);
  return 0;
}