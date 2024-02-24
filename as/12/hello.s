# BP寄存器设计的初衷 记录栈帧基址
.text
.code16

start:
    mov $stack, %sp
    call sum
    
    mov $0x3f8, %dx
    mov $0x41, %al
    out %al, %dx
    hlt

sum:
    # 此时栈帧里面已经放了call指令放进去的函数返回地址
    # 又手动push了主调函数的栈帧基址
    push %bp
    # 此时栈顶sp指向的就是被调函数的栈帧基址了 维护到BP寄存器中
    mov %sp, %bp
    # 上面两行代码会被简化为enter指令

    mov $1, %bx
    mov $0, %ax

1:
    add %bx, %ax
    inc %bx
    cmp $10, %bx
    jbe 1b

    mov $0x3f8, %dx
    out %ax, %dx

    # 通过移动栈顶指针的方式销毁当前函数的栈帧
    # 不管现在栈顶SP指向哪儿 直接拉到当前函数的栈帧基址地方
    mov %bp, %sp
    # 此时当前函数栈帧还存储着两个信息 从低到高依次是 主调函数的栈帧基址 主调函数的返回地址
    # 被调函数要执行ret结束了 恢复BP 指向主调函数的栈帧基址
    pop %bp
    # 上面这两行代码会被简化为leave指令
    ret

.org 0x1000
stack: