# 实现选择结构
# 比较一处内存地址中的值和字符A
# 当该内存中值等于字符A时向串口输出字符A
# 否则向串口输出字符B

.text
.code16
start:
    mov $0x3f8, %dx

    cmp $'A', var
    jne 1f
    mov $'A', %al
    jmp 2f

1:
    mov $'B', %al

2:
    out %al, %dx
    hlt
    
var:
    .byte 0x41
