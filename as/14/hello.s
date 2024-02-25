.text
.code16

start:
    mov $stack, %sp

    # 调用函数sum的参数入栈
    push $10
    call sum
    hlt

.org 0x1000
stack:
