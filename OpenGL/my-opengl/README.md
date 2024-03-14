my-opengl
---

OpenGL的代码示例

[踩到的坑](./doc/ISSUE.md)

### 1 前置依赖

[learn-opengl网站教程](https://learnopengl.com/Getting-started/Creating-a-window)

- [GLFW link With CMake and GLFW source](https://www.glfw.org/docs/latest/build_guide.html)

  - create an OpenGL context
  - define window parameters
  - handle user input

- OpenGL library on Linux

  - libGL.so

- [Glad](https://glad.dav1d.de/)

  - include directory
  - add the `glad.c` file to project

- Make sure you have OpenGL versions 3.3 or higher installed on your system/hardware otherwise the application will crash or display undefined behavior

  - linux上使用`glxinfo`工具命令
  - windows上使用`OpenGL Extensions Viewer`工具

### 2 细节

```cpp
#include <glad/glad.h>
#include <GLFW/glfw3.h>
```

===Be sure to include GLAD before GLFW.===

The include file for GLAD includes the required OpenGL headers behind the scenes (like GL/gl.h) so be sure to include GLAD before other header files that require OpenGL (like GLFW).