cmake_minimum_required(VERSION 3.25.0)

# 编译
add_custom_target(
    libdraw_compile
    ALL
    COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/draw.c -o draw.o
    COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/fonts.c -o fonts.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    libdraw_ld
    ALL
    COMMAND ld -r ${CMAKE_CURRENT_BINARY_DIR}/draw.o ${CMAKE_CURRENT_BINARY_DIR}/fonts.o -o libdraw.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS libdraw_compile
    COMMENT "链接"
)
