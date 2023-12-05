cmake_minimum_required(VERSION 3.25)

project(cmake_03)

#[[
静态库输出路径
这行指令要在add_library之前被定义好
]]
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

#[[
编译为库文件
指定编译成的库文件类型
STATIC
SHARED
不指定库文件类型 默认是静态
]]
add_library(${PROJECT_NAME} STATIC adder.c)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER adder.h)