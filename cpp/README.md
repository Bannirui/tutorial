cpp
---

为什么要心血来潮碰cpp呢，人生苦短何必自找苦吃

因为想认认真真学习openjdk，cpp是迈不过去的坎

### 1 开发环境

- 本地mac

- ssh远程linux

- gcc(g++)

- cmake

- make

### 2 How c++ works

- 编译器将源文件编译为obj中间文件

- 连接器负责链接对象文件为可执行程序

声明

定义

编译命令

- 预处理阶段 g++ -E main.cpp -o main.i

- 编译阶段 g++ -S main.i -o main.s

- 汇编阶段 g++ -c main.s -o main.o

- 链接阶段 函数库的搜索路径 gcc会到系统默认搜索路径/usr/lib

### 代码示例

- [01 开发环境](./01)

- [02 编译过程](./02/)