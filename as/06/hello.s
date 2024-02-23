.text
.code16

start:
    mov $var, %ebx
    mov $0, %esi
    mov $0, %ax

l:
    add (%ebx, %esi, 2), %ax

    add $1, %esi
    cmp $5, %esi
    jb l
    hlt

var:
    .word 1
    .word 2
    .word 3
    .word 4
    .word 5
