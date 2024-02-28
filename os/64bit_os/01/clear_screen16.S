# 清屏
.text
.code16

.global clear_screen

clear_screen:
    push %bp
    mov %sp, %bp

    mov $0x0600, %ax
    mov $0x0700, %bx
    mov $0x0, %cx
    mov $0x184f, %dx
    int $0x10

    mov %bp, %sp
    pop %bp
    ret