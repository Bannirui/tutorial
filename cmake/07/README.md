1 项目结构
---

```txt
.
├── Adder                    模块化的一个功能 单独编译成库使用
│   ├── adder.c        模块的源码
│   └── include        模块的头文件
├── external                 存放三方库
│   └── zlog           三方库的源码 通过git submodule管理组织
├── TestConfig.h.in          .h.in文件 使用cmake的configure_file自动生成文件
├── main.c                   项目源码
├── build.sh                 脚本-make来build项目
├── configure.sh             脚本-cmake生成Makefile文件
└── run.sh                   脚本-运行编译的程序
```

2 本节展涉及的cmake操作
---

- cmake生成构建器
- 构建工具编译项目
- 运行程序
- 使用cmake托管`git submodule`的更新工作
- configure_file指令生成文件
- option指令开关控制编译 通过cmake的-D传递宏定义
- 再谈install
- cpack打包

### 2.1 cmake生成构建器

```shell
cmake -S . -B build
```
### 2.2 使用make构建工具

```shell
cd build
make
```

### 2.3 运行可执行程序

```shell
cd build
./out
```

### 2.4 关于git的子模块

```shell
git submodule add ${remote-repo-url} ${local-repo-name}
git submodule update --init --recursive 
```

我当前项目的规划并不是真实项目结构，因此cmake不会执行git子模块的更新操作

- 项目根目录下初始化git
- 在项目根目录下创建CMakeLists.txt文件，即cmake从项目根目录开始管理
- .gitmodules文件也维护在项目根目录下

### 2.5 关于install

```shell
cmake -S . -B build
cd build ; make install
```

我个人还是不习惯于使用install

- 首先在不同的平台上，不同的编译器实现可能默认的搜索路径并不相同，比如/usr/local/include可能在mac上不会被默认扫描，最终还是要手动添加头文件路径，也就失去了一半的install意义
- 其次在git submodule管理大量的子模块时候，恰好子模块也是通过cmake管理的，恰好也支持install指令，那么将会有比较多的文件被复制到/usr/local下的bin lib或者include文件夹 我不太喜欢这样的不可控的预期
- ld /usr/lib
- 那么当有的时候需要在环境变量中执行程序怎么办，要么手动复制到/usr/local对应目录下，要么将可执行程序对应路径export到全局环境变量中

#### 2.5.1

```shell
❯ ldd main
        linux-vdso.so.1 (0x00007f2cda4fa000)
        libzlog.so.1 => not found
        libc.so.6 => /usr/lib/libc.so.6 (0x00007f2cda200000)
        /lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f2cda4fc000)

```

#### 2.5.2

```shell
cp /usr/local/lib/libzlog.so.1 /usr/lib/
```

#### 2.5.3

```shell
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

#### 2.5.4

.zshrc
```shell
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```
```

### 2.6 cpack指令

```shell
cmake -S . -B build
cd build; cpack
```

cpack是cmake内置功能，需要在CMakeLists.txt中通过`include(CPack)`指令显式开启，并指定相关配置。

- cmake -S . -B build
- cd build; cpack
- 之后在build文件夹下生成.sh和压缩包
- 运行.sh即可对压缩包进行解压

但是我使用的三方库zlog，项目对其有动态库依赖，运行程序的时候报错找不到动态库。
我还不知道如何正确打包这种依赖的动态库，比较简单的方法是将动态库放到/usr/lib中可以让程序运行起来，但这种方法不免有点笨拙。