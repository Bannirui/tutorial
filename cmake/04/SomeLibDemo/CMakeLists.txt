cmake_minimum_required(VERSION 3.25)

project(cmake_04)

#[[
编译为库文件
指定编译成的库文件类型
STATIC
SHARED
不指定库文件类型 默认是静态
]]
add_library(${PROJECT_NAME} SHARED adder.c)

# 把头文件也install到环境变量上
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER adder.h)

#[[
动态库用LIBRARY
静态路用ARCHIVE
头文件install到/usr/local/include中去
库文件install到/usr/local/lib中去
]]
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)