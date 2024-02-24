.text
.code16

start:
    # 向上偏移0x1000 这个高地址作为栈底
    mov $stack, %sp
    mov $0x3f8, %dx

    # 16位系统默认压入16bit
    push $0x41
    push $0x42

    # kvmtool初始化时给段寄存器的值都是0x1000
    # 即DS和SS都是一样的
    # DS<<4+(0x1000-2)=0x10ffe
    # 入栈的时候两个元素分别是16位 2个byte
    mov 0x1000-2, %ax
    out %ax, %dx
    mov 0x1000-4, %ax
    out %ax, %dx

    pop %ax
    out %ax, %dx
    pop %ax
    out %ax, %dx

    hlt

.org 0x1000
stack: