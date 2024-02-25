.text
.code16

start:
    mov $stack, %sp

    # 记录当前函数的栈帧基址BP
    mov %sp, %bp

    # 栈帧中开辟空间存放局部变量 用来接收sum函数的返回值 大小2byte
    # 锚点是BP 局部变量的地址是BP-2
    sub $2, %sp

    # 调用函数sum的参数入栈
    # 锚点是BP 比如这个sum函数就1个参数 16默认push16bit
    # 参数地址是BP+2
    push $10
    call sum
    # 被调函数将函数结果放在了AX寄存器上了 把sum函数的返回值放到局部变量上
    mov %ax, -2(%bp)

    # 清理调用sum函数的参数
    add $2, %sp

    # 打印sum的结果
    mov $0x3f8, %dx
    out %ax, %dx

    hlt

.org 0x1000
stack:
