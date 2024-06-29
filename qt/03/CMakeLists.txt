cmake_minimum_required(VERSION 3.28)
project(03 CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(CMAKE_PREFIX_PATH "/Users/dingrui/Qt/6.7.0/macos")
elseif (LINUX)
    set(CMAKE_PREFIX_PATH "/home/dingrui/MyApp/Qt/6.7.0/gcc_64")
endif ()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# 源码
aux_source_directory(. PROJ_SRCS)
add_executable(03 ${PROJ_SRCS})

target_link_libraries(03
        Qt::Core
        Qt::Gui
        Qt::Widgets
)