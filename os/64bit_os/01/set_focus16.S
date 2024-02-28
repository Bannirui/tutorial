# 设置屏幕光标位置
.text
.code16

.global set_focus

set_focus:
    push %bp
    mov %sp, %bp

    mov $0x0200, %ax
    mov $0x0000, %bx
    mov $0x0000, %dx
    int $0x10

    mov %bp, %sp
    pop %bp
    ret