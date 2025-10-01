cmake_minimum_required(VERSION 4.0)

project(my_cuda CUDA)

set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
file(GLOB_RECURSE SRCS ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.h ${SOURCE_DIR}/*.cu)

add_executable(${PROJECT_NAME} ${SRCS})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
