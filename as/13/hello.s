.text
.code16

start:
    mov $stack, %sp
    call sum
    hlt

.org 0x1000
stack: