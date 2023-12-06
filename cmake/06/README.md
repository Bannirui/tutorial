使用cmake托管`git submodule`的工作`

正常项目结构规划而言

- 项目根目录下初始化git
- 在项目根目录下创建CMakeLists.txt文件，即cmake从项目根目录开始管理
- .gitmodules文件也维护在项目根目录下

我当前项目的规划并不是真实项目结构，因此cmake不会执行git子模块的更新操作

本节展涉及的cmake操作
- git submodule更新管理
- configure_file指令生成文件