.text
.code16

start:
    # 源操作数0x41会直接潜入指令mov的立即数字段中
    mov $0x41, %al
    # 向前跳转到标签l
    # jmp的目标地址被嵌入了指令的立即数字段中
    jmp l
    # 源操作数0x42会直接潜入指令mov的立即数字段中
    mov $0x42, %al

l:
    # 源操作数0x3f8会直接潜入指令mov的立即数字段中
    mov $0x3f8, %dx
    out %al, %dx
    hlt
