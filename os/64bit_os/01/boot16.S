.text
.code16

.org 0x7c00

.equ BaseOfStack, 0x7c00

start:
    # cs->ds
    mov %cs, %ax
    mov %ax, %ds
    # cs->es
    mov %ax, %es
    # cs->ss
    mov %ax, %ss
    # 栈底0x7c00
    mov $BaseOfStack, %sp

    # 清屏
    call clear_screen
    # 设置屏幕光标位置
    call set_focus
    # 字符串打印
    call display_Start_Boot

    # 软盘引导程序只能装载第一扇区 以0x55 0xaa结束标识
    .rept 510-(.-start)
    .byte 0
    .endr
    # intel处理器是小端存储 低位放0x55 高位放0xaa
    .int 0xaa55