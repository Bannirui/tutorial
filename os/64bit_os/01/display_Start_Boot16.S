# 打印字符串 Start Boot
.text
.code16

.global display_Start_Boot

display_Start_Boot:
    push %bp
    mov %sp, %bp

    mov $0x1301, %ax
    mov $0x000f, %bx
    mov $0x0000, %dx
    mov $0x10, %cx
    push %ax
    mov %ds, %ax
    mov %ax, %es
    pop %ax
    mov $msg, %bp
    int $0x10

    mov %bp, %sp
    pop %bp
    ret

msg:
    .ascii "Start Boot"