cmake_minimum_required(VERSION 3.25.0)
project(learn_os)

add_definitions(-std=gnu11)

# 可执行程序 用来组装映像
add_executable(buildup buildup.c)

# 指定头文件搜索路径 搜索顺序在标准库之前
set(my_include "-I${CMAKE_CURRENT_SOURCE_DIR}")
set(my_cflags ${my_include})
# 位置相关代码
set(my_cflags "${my_cflags} -fno-pic")
# 内核运行于2GB地址空间之外
set(my_cflags "${my_cflags} -mcmodel=kernel")
# 禁用栈保护机制
set(my_cflags "${my_cflags} -fno-stack-protector")
set(my_cflags "${my_cflags} -fcf-protection=none")
# 不搜索默认路径头文件
set(my_cflags "${my_cflags} -nostdinc")
# 不使用C语言的内建函数
set(my_cflags "${my_cflags} -fno-builtin")

#add_subdirectory(app)
add_subdirectory(kernel)

# 启用汇编语言支持
enable_language(ASM)

# 编译和汇编 不链接
add_custom_target(
        as
        ALL
        # boot16
        COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot16.S -o boot16.o
        COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot32.S -o boot32.o
        COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/head64.S -o head64.o
        COMMENT "汇编"
)

execute_process(
        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/main.c -o ${CMAKE_CURRENT_BINARY_DIR}/main.o
)
# 预处理 编译和汇编 不链接 生成.o文件
add_custom_target(
        compile
        ALL
        COMMENT "编译汇编"
        # main
        #        # driver
        #        COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/drivers
        #        #COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/drivers/atkbd.c -o ${CMAKE_CURRENT_BINARY_DIR}/drivers/atkbd.o
        #        COMMAND gcc ${my_cflags} -c ./drivers/atkbd.c -o ./atkbd.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/drivers/vesa.c -o ${CMAKE_CURRENT_BINARY_DIR}/drivers/vesa.o
        #        # ipc
        #        COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/ipc
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/ipc/shm.c -o ${CMAKE_CURRENT_BINARY_DIR}/ipc/shm.o
        #        # kernel
        #        COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/kernel
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/ipc/shm.c -o ${CMAKE_CURRENT_BINARY_DIR}/ipc/shm.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/interrupt.c -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/interrupt.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/sched.c -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/sched.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/syscall.c -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/syscall.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/kernel/tss.c -o ${CMAKE_CURRENT_BINARY_DIR}/kernel/tss.o
        #        # lib
        #        COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/lib
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/lib/string.c -o ${CMAKE_CURRENT_BINARY_DIR}/lib/string.o
        #        # mm
        #        COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/mm
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/mm/malloc.c -o ${CMAKE_CURRENT_BINARY_DIR}/mm/malloc.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/mm/memory.c -o ${CMAKE_CURRENT_BINARY_DIR}/mm/memory.o
        #        COMMAND gcc ${my_cflags} -c ${CMAKE_CURRENT_SOURCE_DIR}/mm/page_alloc.c -o ${CMAKE_CURRENT_BINARY_DIR}/mm/page_alloc.o
)

# 链接
add_custom_target(
        ld
        ALL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ld -Ttext=0x0 ${CMAKE_CURRENT_BINARY_DIR}/boot16.o -o boot16.elf
        COMMAND ld -Ttext=0x20000 ${CMAKE_CURRENT_BINARY_DIR}/boot32.o -o boot32.elf
        #    COMMAND ld -Ttext=0xffffffff80100000 ${CMAKE_CURRENT_BINARY_DIR}/head64.o ${CMAKE_CURRENT_BINARY_DIR}/main.o ${CMAKE_CURRENT_BINARY_DIR}/handle.o  ${CMAKE_CURRENT_BINARY_DIR}/malloc.o ${CMAKE_CURRENT_BINARY_DIR}/memory.o ${CMAKE_CURRENT_BINARY_DIR}/page_alloc.o ${CMAKE_CURRENT_BINARY_DIR}/string.o ${CMAKE_CURRENT_BINARY_DIR}/interrupt.o ${CMAKE_CURRENT_BINARY_DIR}/sched.o ${CMAKE_CURRENT_BINARY_DIR}/syscall.o ${CMAKE_CURRENT_BINARY_DIR}/tss.o ${CMAKE_CURRENT_BINARY_DIR}/shm.o ${CMAKE_CURRENT_BINARY_DIR}/atkbd.o ${CMAKE_CURRENT_BINARY_DIR}/vesa.o -o system.elf
        DEPENDS as compile
        COMMENT "链接"
)

# binary可执行文件
add_custom_target(
        copy
        ALL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND objcopy -O binary boot16.elf boot16.bin
        COMMAND objcopy -O binary boot32.elf boot32.bin
        #COMMAND objcopy -O binary system.elf system.bin
        DEPENDS ld
        COMMENT "bin可执行文件"
)
#
## 组装映像
#add_custom_target(
#    build_boot
#    ALL
#    COMMAND ./buildup
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#    DEPENDS buildup
#    COMMENT "组装boot映像文件"
#)