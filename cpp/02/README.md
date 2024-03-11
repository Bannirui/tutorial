编译过程
---

- 编译器将源文件编译为obj中间文件

- 连接器负责链接对象文件为可执行程序

声明

定义

编译命令

- 预处理阶段 g++ -E main.cpp -o main.i

- 编译阶段 g++ -S main.i -o main.s

- 汇编阶段 g++ -c main.s -o main.o

- 链接阶段 函数库的搜索路径 gcc会到系统默认搜索路径/usr/lib