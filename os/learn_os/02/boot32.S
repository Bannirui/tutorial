// 32位保护模式
.section .text
.code32

.global _start
_start:
    mov $0x3f8, %dx
    mov $'A', %al
    out %al, %dx

loop:
    jmp loop
    
    hlt