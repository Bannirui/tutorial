# 指定cmake的最低版本要求
cmake_minimum_required(VERSION 3.25)

# 项目名称 前置定义好 后面要使用该变量
project(cmake_01)

#[[
编译为可执行程序
使用了上面定义好的变量-项目名称
源文件
]]
add_executable(${PROJECT_NAME} main.c)