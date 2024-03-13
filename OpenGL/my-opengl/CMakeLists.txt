cmake_minimum_required(VERSION 3.25)

project(my-opengl)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# 源码
file(GLOB src_files src/*.cpp)

add_executable(${PROJECT_NAME}
        ${src_files}
        external/glad/src/glad.c # glad的源文件加到项目中
)

# 编译GLFW源码
add_subdirectory(external/glfw)
find_package(OpenGL REQUIRED)

# 头文件目录
target_include_directories(${PROJECT_NAME}
        PUBLIC external/glad/include # glad
        PUBLIC external/glfw/include # glfw
)

# 库文件目录
#target_link_directories(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)