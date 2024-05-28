// 64位模式

.section .text
.code64

.global _start
_start:
  mov $0x3f8, %dx
  mov $'L', %ax
  out %ax, %dx

  hlt