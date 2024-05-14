build GLFW
---

### 1 前置依赖

- [GLFW link With CMake and GLFW source](https://www.glfw.org/docs/latest/build_guide.html)

    - create an OpenGL context
    - define window parameters
    - handle user input

- OpenGL library on Linux

    - libGL.so

- [Glad](https://glad.dav1d.de/)

    - include directory
    - add the `glad.c` file to project

- Make sure you have OpenGL versions 3.3 or higher installed on your system/hardware otherwise the application will
  crash or display undefined behavior

    - linux上使用`glxinfo`工具命令
    - windows上使用`OpenGL Extensions Viewer`工具

### 2 细节

```cpp
#include <glad/glad.h>
#include <GLFW/glfw3.h>
```

===Be sure to include GLAD before GLFW.===

The include file for GLAD includes the required OpenGL headers behind the scenes (like GL/gl.h) so be sure to include
GLAD before other header files that require OpenGL (like GLFW).

### 3 开发环境

在尝试mac+ssh+linux的环境，发现x11转发问题，配置VirtualGL过于复杂

放弃了远程开发方式，改成本地开发

| 环境    | opengl | glfw | glad   | opengl版本查询方式                           |
|-------|--------|------|--------|----------------------------------------|
| linux | 4.6    | 3.4  | gl=4.6 | glxinfo                                |
| mac   | 4.1    | 3.4  | gl=4.6 | https://support.apple.com/zh-cn/101525 |