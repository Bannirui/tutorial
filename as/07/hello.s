.text
.code16

start:
    mov $0, %ebx
    mov $1, %esi
    mov $0, %ax

1:
    add var(%ebx, %esi, 2), %ax
    
    add $6, %ebx
    cmp $12, %ebx
    # 向后跳转到标签1
    jbe 1b

    hlt

var:
    .word 1
    .word 2
    .word 3

    .word 1
    .word 2
    .word 3

    .word 1
    .word 2
    .word 3
