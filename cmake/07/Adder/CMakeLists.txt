project(adder)

# 头文件目录
include_directories(include)

#[[
编译为库文件
指定编译成的库文件类型
STATIC
SHARED
不指定库文件类型 默认是静态
]]
add_library(${PROJECT_NAME} STATIC adder.c)

# 库文件install到/usr/local/lib中
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# 头文件install到/usr/local/include中
install(FILES include/adder.h DESTINATION include)