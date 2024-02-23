.text
.code16

start:
    mov $0x3f8, %dx
    # 标签地址本质是一个立即数 取标签地址时在标签前面加上符号$
    # 将var1标签的地址装载到寄存器中
    # BX寄存器中存储的是0x50
    mov $var1, %bx

    # 用括号将源操作数寄存器括起来表示以寄存器中的值作为内存地址 读取该内存地址上的内容装载到寄存器中
    # 数据DS<<4+0x50上的字符A读取出来装载到AL中
    mov (%bx), %al
    out %al, %dx

    # 首先读取BX寄存器中的值作为基址 0x50
    # 然后在这个基址上增加一个位移0x10
    # 作为操作数的内存地址 0x60
    mov 0x10(%bx), %al
    out %al, %dx

    hlt

.org 0x50
var1:
    # A
    .byte 0x41

.org 0x60
var2:
    # B
    .byte 0x42
