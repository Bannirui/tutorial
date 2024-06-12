cmake_minimum_required(VERSION 3.25.0)

# 编译
add_custom_target(
    libc_compile
    ALL
    COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/syscall.c -o syscall.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    libc_ld
    ALL
    COMMAND ld -r ${CMAKE_CURRENT_BINARY_DIR}/syscall.o -o libc.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS libc_compile
    COMMENT "链接"
)
