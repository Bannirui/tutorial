cmake_minimum_required(VERSION 3.25)

project(test)

#[[
头文件目录
这样就没必要使用相对目录了
直接把头文件放到某个目录
然后告知编译器去扫对应目录
]]
include_directories(include)

# 编译可执行程序
add_executable(${PROJECT_NAME} main.c)

#[[
库文件目录
必须声明作用域PRIVATE等
]]
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 链接库文件
target_link_libraries(${PROJECT_NAME} cmake_03)