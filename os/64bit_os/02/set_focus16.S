# 设置屏幕光标位置
# 该函数不需要参数
.text
.code16

.global set_focus

# 中断号int 0x10
# 功能号AH=0x02
# DH=游标的列号(0-based)
# DH=游标的行号(0-based)
# BH=页码
set_focus:
    push %bp
    mov %sp, %bp

    # AL=0x02 功能号
    mov $0x0200, %ax
    # BH=0x00 页码固定死
    mov $0x0, %bx
    # 光标位置固定死
    mov $0x0, %dx
    int $0x10

    mov %bp, %sp
    pop %bp
    ret