cmake_minimum_required(VERSION 3.25.0)
project(learn_os)

add_definitions(-std=gnu11)

set(my_cflags "-I. -fno-pic -mcmodel=kernel -fno-stack-protector -fcf-protection=none -nostdinc -fno-builtin -MM")

add_subdirectory(app)
add_subdirectory(drivers)

# 可执行程序 用来组装映像
add_executable(buildup buildup.c)

# 启用汇编语言支持
enable_language(ASM)

# 编译和汇编 不链接
add_custom_target(
    as
    ALL
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot16.S -o boot16.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot32.S -o boot32.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/head64.S -o head64.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 编译和汇编 不链接
add_custom_target(
    compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/main.c -o ${CMAKE_CURRENT_BINARY_DIR}/main.o
    COMMENT "编译main"
)

# 链接
add_custom_target(
    ld
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ld -Ttext=0x0 ${CMAKE_CURRENT_BINARY_DIR}/boot16.o -o boot16.elf
    COMMAND ld -Ttext=0x20000 ${CMAKE_CURRENT_BINARY_DIR}/boot32.o -o boot32.elf
    COMMAND ld -Ttext=0xffffffff80100000 ${CMAKE_CURRENT_BINARY_DIR}/head64.o ${CMAKE_CURRENT_BINARY_DIR}/main.o ${CMAKE_CURRENT_BINARY_DIR}/handle.o  ${CMAKE_CURRENT_BINARY_DIR}/malloc.o ${CMAKE_CURRENT_BINARY_DIR}/memory.o ${CMAKE_CURRENT_BINARY_DIR}/page_alloc.o ${CMAKE_CURRENT_BINARY_DIR}/string.o ${CMAKE_CURRENT_BINARY_DIR}/interrupt.o ${CMAKE_CURRENT_BINARY_DIR}/sched.o ${CMAKE_CURRENT_BINARY_DIR}/syscall.o ${CMAKE_CURRENT_BINARY_DIR}/tss.o ${CMAKE_CURRENT_BINARY_DIR}/shm.o ${CMAKE_CURRENT_BINARY_DIR}/atkbd.o ${CMAKE_CURRENT_BINARY_DIR}/vesa.o -o system.elf
    DEPENDS as compile
    COMMENT "链接"
)

# binary可执行文件
add_custom_target(
    copy
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    #COMMAND objcopy -O binary boot16.elf boot16.bin
    #COMMAND objcopy -O binary boot32.elf boot32.bin
    #COMMAND objcopy -O binary system.elf system.bin
    DEPENDS ld
    COMMENT "bin可执行文件"
)

# 组装映像
add_custom_target(
    build_boot
    ALL
    #COMMAND ./buildup
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS buildup
    COMMENT "组装boot映像文件"
)