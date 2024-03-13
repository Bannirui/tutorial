OpenGL
---

### 1 linux上编译GLFW

#### 1.1 源码

[参看官网文档](https://www.glfw.org/docs/latest/compile.html)

```shell
cd ~/MyDev/env/glfw

git clone git@github.com:glfw/glfw.git

git checkout -b my-compile
```

#### 1.2 cmake执行

##### 1.2.1 创建2个文件

```shell
chmod +x ./configure.sh

chmod +x ./build.sh
```

##### 1.2.2 脚本内容如下

- configure.sh

    ```shell
    #!/bin/sh

    cmake \
        -G "Unix Makefiles" \
        -S . \
        -B build
    ```

- build.sh

    ```shell
    #!/bin/sh

    cd build ; make
    ```

##### 1.2.3 执行cmake

```shell
./configure.sh
```

#### 1.3 make编译

```shell
./build.sh
```

至此没有报错，说明我编译GLFW需要的依赖我的系统是不缺失的

我并没有将库文件安装到电脑的`/usr/bin`或者`/usr/local/bin`上，因为我并不喜欢这样

我的习惯是如果项目依赖三方库，我会用git统一管理到源码中

### 2 OpenGL开发

示例代码在直接以[my-opengl项目为例](./my-opengl/)