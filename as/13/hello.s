.section .text
.code16

.global _start
_start:
    mov $stack, %sp
    call sum
    hlt

.org 0x1000
stack: