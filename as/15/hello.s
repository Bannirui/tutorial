.text
.code16

start:
    mov $stack, %sp

    # 调用函数sum的参数 用寄存器进行传参
    mov $10, %di
    call sum
    hlt

.org 0x1000
stack:
