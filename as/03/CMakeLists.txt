cmake_minimum_required(VERSION 3.25.0)
project(hello)

# 启用汇编语言支持
enable_language(ASM)

# 汇编
add_custom_target(
    as
    ALL
    COMMAND as ${CMAKE_CURRENT_SOURCE_DIR}/hello.s -o hello.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    ld
    ALL
    COMMAND ld -Ttext=0 ${CMAKE_CURRENT_BINARY_DIR}/hello.o -o hello.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS as
    COMMENT "链接"
)

# binary可执行文件
add_custom_target(
    copy
    ALL
    COMMAND objcopy -O binary hello.elf hello.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "bin可执行文件"
)

# 反汇编
add_custom_target(
    dump
    ALL
    COMMAND objdump -d -m i8086 ${CMAKE_CURRENT_BINARY_DIR}/hello.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "可执行文件ELF反汇编"
)