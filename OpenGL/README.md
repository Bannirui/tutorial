OpenGL
---

### 1 linux上编译GLFW

#### 1.1 源码

[参看官网文档](https://www.glfw.org/docs/latest/compile.html)

![](./img/1714870408.png)

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

### 2 [Learn OpenGL](https://learnopengl.com/)

### 3 OpenGL开发

[learn-opengl网站教程](https://learnopengl.com/Getting-started/Creating-a-window)

- [X] [01 build GLFW](demo/01/README.md)

- [X] [02 window](demo/02/README.md)

- [X] [03 triangle](demo/03/README.md)

- [X] [04 rectangle](demo/04/README.md)