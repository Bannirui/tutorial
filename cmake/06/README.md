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

- 使用cmake托管`git submodule`的更新工作
- configure_file指令生成文件
- option指令开关控制编译 通过cmake的-D传递宏定义
- 再谈install

### 2.1 关于git的子模块

我当前项目的规划并不是真实项目结构，因此cmake不会执行git子模块的更新操作

- 项目根目录下初始化git
- 在项目根目录下创建CMakeLists.txt文件，即cmake从项目根目录开始管理
- .gitmodules文件也维护在项目根目录下

### 2.2 关于install

我个人还是不习惯于使用install

- 首先在不同的平台上，不同的编译器实现可能默认的搜索路径并不相同，比如/usr/local/include可能在mac上不会被默认扫描，最终还是要手动添加头文件路径，也就失去了一半的install意义
- 其次在git submodule管理大量的子模块时候，恰好子模块也是通过cmake管理的，恰好也支持install指令，那么将会有比较多的文件被复制到/usr/local下的bin lib或者include文件夹 我不太喜欢这样的不可控的预期
- 那么当有的时候需要在环境变量中执行程序怎么办，要么手动复制到/usr/local对应目录下，要么将可执行程序对应路径export到全局环境变量中
