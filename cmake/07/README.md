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

- 首先在不同的平台上，不同的编译器实现可能默认的搜索路径并不相同，比如/usr/local/include可能在不会被默认扫描，最终还是要手动添加头文件路径到CMakeLists文件，也就失去了一半的install意义
- 其次在git submodule管理大量的子模块时候，恰好子模块也是通过cmake管理的，恰好也支持install指令，那么将会有比较多的文件被复制到/usr/local下的bin lib或者include文件夹 我不太喜欢这样的不可控的预期
- 默认情况下习惯性将库install到/usr/local/lib中，但是系统默认的依赖库路径在/usr/lib中，这样就会导致可执行程序找不到动态库

比如上述原因，我们编译好的程序运行不了怎么处理

#### 2.5.1 首先分析程序链接不到哪个库

```shell
❯ ldd main
        linux-vdso.so.1 (0x00007f2cda4fa000)
        libzlog.so.1 => not found
        libc.so.6 => /usr/lib/libc.so.6 (0x00007f2cda200000)
        /lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f2cda4fc000)

```

main程序链接不到`zlog.so.1`这个动态库，但是这个库在`make install`的时候已经安装到了`/usr/local/lib`下，说明系统默认的库依赖路径并不包含`/usr/local/lib`这个路径。

#### 2.5.2 将库放到/usr/lib中

`/usr/lib`是系统的默认依赖库路径，将动态库放到这个路径下，main程序便能够成功链接到该库。

```shell
cp /usr/local/lib/libzlog.so.1 /usr/lib/
```

#### 2.5.3 将/usr/local/lib暴露给库依赖路径

修改LD_LIBRARY_PATH环境变量，这个时候可以有临时和永久两种方式

- 在终端的一次会话生命周期内修改环境
- 添加到全局环境变量中

##### 2.5.3.1 终端会话修改环境变量

```shell
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

##### 2.5.3.2 修改全局环境变量

```shell
vim ~/.zshrc

将下面这行添加到文件中
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

source ~/.zshrc
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

但是因为我仍旧不习惯在`/usr/lib`全局库路径安装用户级别的库，所以当前示例项目的压缩包解压后运行还会提示缺少动态库。