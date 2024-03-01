.text
.code16

# 基址偏移0x7c00 这个地址向上是代码和数据 以它作为栈底 栈从高向下
.equ BaseOfStack, 0x7c00

start16:
    # cs->ds
    mov %cs, %ax
    mov %ax, %ds
    # cs->es
    mov %ax, %es
    # cs->ss
    mov %ax, %ss
    mov $BaseOfStack, %sp

    # 清屏
    call clear_screen

    # 设置屏幕光标位置
    call set_focus

    # 字符串打印 栈传递3个参数
    # 第1个参数是字符串长度
    # 第2个参数是字符串地址
    # 第3个参数是字符串显示的位置
    push $0x10
    push $BootMsg
    push $0x0a1f
    call print_msg

# 函数的实现本来计划是模块化 在ld链接的时候再关联起来 但是这样可能会导致最终的可执行文件最后2个byte不是0x55和0xaa标识
# 因此换用gcc的预处理指令
#include "clear_screen16.S"
#include "set_focus16.S"
#include "print_msg16.S"

loop:
    jmp loop

# 定义变量
var:
    BootMsg: .ascii "Hello World....."

# 软盘引导程序只能装载第一扇区 总共512byte 最后2个byte以0x55 0xaa结束标识
.org 510
    # intel处理器是小端存储 低位放0x55 高位放0xaa
    .word 0xaa55