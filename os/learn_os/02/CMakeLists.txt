cmake_minimum_required(VERSION 3.25.0)
project(learn_os)

add_subdirectory(app)

# 可执行程序 用来组装映像
add_executable(buildup buildup.c)

# 启用汇编语言支持
enable_language(ASM)

# 汇编
add_custom_target(
    as
    ALL
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot16.S -o boot16.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot32.S -o boot32.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/head64.S -o head64.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 编译c
add_custom_target(
    compile
    ALL
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/main.c -o main.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/mm/malloc.c -o malloc.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/mm/memory.c -o memory.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/mm/page_alloc.c -o page_alloc.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/lib/string.c -o string.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/kernel/interrupt.c -o interrupt.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/kernel/sched.c -o sched.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/kernel/syscall.c -o syscall.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/kernel/tss.c -o tss.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/ipc/shm.c -o shm.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/drivers/atkbd.c -o atkbd.o
    COMMAND gcc -I. MM ${CMAKE_CURRENT_SOURCE_DIR}/drivers/vesa.c -o vesa.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    ld
    ALL
    COMMAND ld -Ttext=0x0 ${CMAKE_CURRENT_BINARY_DIR}/boot16.o -o boot16.elf
    COMMAND ld -Ttext=0x20000 ${CMAKE_CURRENT_BINARY_DIR}/boot32.o -o boot32.elf
    COMMAND ld -Ttext=0xffffffff80100000 \
    ${CMAKE_CURRENT_BINARY_DIR}/head64.o \
    ${CMAKE_CURRENT_BINARY_DIR}/kernel/handle.o \
    ${CMAKE_CURRENT_BINARY_DIR}/main.o \
    ${CMAKE_CURRENT_BINARY_DIR}/mm/malloc.o \
    ${CMAKE_CURRENT_BINARY_DIR}/mm/memory.o \
    ${CMAKE_CURRENT_BINARY_DIR}/mm/page_alloc.o \
    ${CMAKE_CURRENT_BINARY_DIR}/lib/string.o \
    ${CMAKE_CURRENT_BINARY_DIR}/kernel/interrupt.o \
    ${CMAKE_CURRENT_BINARY_DIR}/kernel/sched.o \
    ${CMAKE_CURRENT_BINARY_DIR}/kernel/syscall.o \
    ${CMAKE_CURRENT_BINARY_DIR}/kernel/tss.o \
    ${CMAKE_CURRENT_BINARY_DIR}/ipc/shm.o \
    ${CMAKE_CURRENT_BINARY_DIR}/drivers/atkbd.o \
    ${CMAKE_CURRENT_BINARY_DIR}/drivers/vesa.o \
    -o system.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS as compile
    COMMENT "链接"
)

# binary可执行文件
add_custom_target(
    copy
    ALL
    COMMAND objcopy -O binary boot16.elf boot16.bin
    COMMAND objcopy -O binary boot32.elf boot32.bin
    COMMAND objcopy -O binary system.elf system.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "bin可执行文件"
)

# 组装映像
add_custom_target(
    build_boot
    ALL
    COMMAND ./buildup
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS buildup
    COMMENT "组装boot映像文件"
)