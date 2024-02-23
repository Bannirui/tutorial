.text
.code16

start:
    mov var, %al
    mov $0x3f8, %dx
    out %al, %dx
    hlt

.org 0x20
var:
    # 字符A的ASCII码是0x41
    .byte 0x41
