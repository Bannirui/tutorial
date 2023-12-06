cmake_minimum_required(VERSION 3.25)

project(main)

# 判断系统平台
if (APPLE)
    message("mac电脑")
elseif (LINUX)
    message("linux电脑")
else ()
    message("其他平台")
endif ()

add_executable(${PROJECT_NAME} main.c)

# zlog的目录
add_subdirectory(external/zlog)

# 头文件目录
target_include_directories(${PROJECT_NAME}
        PUBLIC external/zlog/src
)

# 库文件目录
target_link_directories(${PROJECT_NAME}
        PRIVATE external/zlog/lib
)

# 链接库
# libzlog.a
target_link_libraries(${PROJECT_NAME}
        zlog
)