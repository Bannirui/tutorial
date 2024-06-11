cmake_minimum_required(VERSION 3.25.0)

add_subdirectory(libdraw)

# 启用汇编语言支持
enable_language(ASM)

# 汇编
add_custom_target(
    as
    ALL
    COMMAND gcc -I. -c ${CMAKE_CURRENT_SOURCE_DIR}/app1.c -o app1.o
    COMMAND gcc -fno-stack-protector -I. -c ${CMAKE_CURRENT_SOURCE_DIR}/app2.c -o app2.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    ld
    ALL
    COMMAND ld -Ttext=0x100000 \
    ${CMAKE_CURRENT_BINARY_DIR}/app1.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libc/start.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libc/libc.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libdraw/libdraw.o \
    -o app1.elf
    COMMAND ld -Ttext=0x100000 \
    ${CMAKE_CURRENT_BINARY_DIR}/app2.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libc/start.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libc/libc.o \
    ${CMAKE_CURRENT_BINARY_DIR}/app/libdraw/libdraw.o \
    -o app2.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS as
    COMMENT "链接"
)

# binary可执行文件
add_custom_target(
    copy
    ALL
    COMMAND objcopy -O binary app1.elf app1.bin
    COMMAND objcopy -O binary app2.elf app2.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "bin可执行文件"
)