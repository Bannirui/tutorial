cmake_minimum_required(VERSION 3.25)

project(my-opengl)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# 源码
aux_source_directory(src srcs)

add_executable(${PROJECT_NAME}
        ${srcs}
        external/glad/src/glad.c # add `glad.c` to my project
)

add_subdirectory(external/glfw) # 编译GLFW源码
find_package(OpenGL REQUIRED) # libGL.so

# 头文件目录
target_include_directories(${PROJECT_NAME}
        PUBLIC external/glad/include # glad
        PUBLIC external/glfw/include # glfw
)

# 库文件目录
target_link_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_BINARY_DIR}/external/glfw/src # libglfw3.a
)

target_link_libraries(${PROJECT_NAME}
        glfw # 链接库libglfw3.a
        OpenGL::GL # 链接库libGL.so
        ${sys_libs} # 系统库
)

if (LINUX)
    set(sys_libs "-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl") # 依赖的系统库
    target_link_libraries(${PROJECT_NAME}
            ${sys_libs} # 系统库
    )
endif ()