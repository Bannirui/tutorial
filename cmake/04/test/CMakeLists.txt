cmake_minimum_required(VERSION 3.25)

project(test)

#[[
不知道为啥默认的头文件和库搜索路径没有/usr/local
还是得显示指定
]]
# 添加头文件搜索路径
include_directories("/usr/local/include")

# 添加链接库搜索路径
link_directories("/usr/local/lib")

# 编译可执行程序
add_executable(${PROJECT_NAME} main.c)

# 链接库文件
target_link_libraries(${PROJECT_NAME} cmake_04)