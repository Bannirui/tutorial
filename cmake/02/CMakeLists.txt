cmake_minimum_required(VERSION 3.25)

project(cmake_02)

add_executable(${PROJECT_NAME} main.c)

#[[
make install
即可将可目标拷贝到/usr/local/bin中
在全局系统变量的搜索路径相当于安装
]]
install(TARGETS ${PROJECT_NAME} DESTINATION bin)