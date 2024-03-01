cmake_minimum_required(VERSION 3.25.0)
project(64bit_os)

# 启用汇编语言支持
enable_language(ASM)

# bochs配置文件
set(bochs_cfg "${CMAKE_CURRENT_SOURCE_DIR}/../my_bochs_cfg")
# 检查bochs配置文件
if(NOT EXISTS ${bochs_cfg})
    message(FATAL_ERROR "bochs配置文件不存在")
else()
    message(STATUS "bochs配置文件存在")
endif()

# 软盘镜像文件
set(floppy_img "${CMAKE_CURRENT_BINARY_DIR}/my_os_floppy.img")
# 删除旧的软盘镜像
if(EXISTS ${floppy_img})
    message(STATUS "删除过期软盘镜像")
    file(REMOVE ${floppy_img})
else()
    message(STATUS "不存在软盘镜像")
endif()

# 汇编
add_custom_target(
    as
    ALL
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/boot16.S -o boot.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/clear_screen16.S -o clear_screen.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/set_focus16.S -o set_focus.o
    COMMAND gcc -c ${CMAKE_CURRENT_SOURCE_DIR}/print_msg16.S -o print_msg.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "汇编"
)

# 链接
add_custom_target(
    ld
    ALL
    # 软盘第一扇区为引导区 CS=0 IP=0x7c0 处理去取址地址=CS<<4+IP=0x7c00 把代码指定到这个位置
    COMMAND ld -Ttext=0x7c00
        ${CMAKE_CURRENT_BINARY_DIR}/boot.o 
        -o boot.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS as
    COMMENT "链接"
)

# binary可执行文件
add_custom_target(
    copy
    ALL
    COMMAND objcopy -O binary boot.elf boot.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "bin可执行文件"
)

# 反汇编
# 不需要加到ALL中 默认不需要执行 有需要的时候到构建目录下执行make dump
add_custom_target(
    dump
    COMMAND objdump -d -m i8086 ${CMAKE_CURRENT_BINARY_DIR}/boot.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ld
    COMMENT "可执行文件ELF反汇编"
)

# 新建空的软盘
add_custom_target(
    create_floppy
    ALL
    COMMAND bximage -func=create -fd=1.44M -q ${floppy_img}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${bximage_exec}
    COMMENT "创建软盘镜像"
)

# 可执行程序写入软盘
add_custom_target(
    write_floppy
    ALL
    COMMAND dd if=${CMAKE_CURRENT_BINARY_DIR}/boot.bin of=${floppy_img} bs=512 count=1 conv=notrunc
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS create_floppy copy
    COMMENT "引导程序写入软盘"
)