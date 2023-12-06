#include <stdio.h>

// 三方库
#include "zlog.h"
// configure_file自动生成的文件
// 包含了版本号
// 使用adder库的时候引入其头文件
#include <TestConfig.h>

// 模块化编译好的库 由option开关控制是否使用
#ifdef USE_ADDER
#include "adder.h"
#endif

int main(int argc, char **argv)
{
  // 使用adder库的时候使用其提供的函数
#ifdef USE_ADDER
  int a = 1;
  int b = 4;
  printf("测试模块化\n%d+%d=%d\n", a, b, add(a, b));
#else
  printf("没有使用adder库\n");
#endif

  printf("测试configure_file自动生成的文件\nhello world\nVersion %d.%d\n", VERSION_MAJOR, VERSION_MINOR);
  int rc;
  zlog_category_t *c;

  rc = zlog_init("/etc/zlog.conf");
  if (rc) {
	printf("init failed\n");
	return -1;
  }

  c = zlog_get_category("my_cat");
  if (!c) {
	printf("get cat fail\n");
	zlog_fini();
	return -2;
  }

  zlog_info(c, "hello, zlog");

  zlog_fini();

  return 0;
}