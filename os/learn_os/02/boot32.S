// 32位保护模式
.section .data
gdt:
  .quad 0x0000000000000000
  .quad 0x00209a0000000000
  .quad 0x0000920000000000
gdt_end:

gdtr:
  .word gdt_end-gdt
  .long gdt

.org 0x10000
  .quad 0x0000000000053003
  .fill 510, 8, 0
  .quad 0x0000000000031003

.org 0x11000
  .fill 510, 8, 0
  .quad 0x0000000000032003
  .fill 1, 8, 0

.org 0x12000
  .fill 512, 8, 0

.org 0x13000
  .fill 512*32, 8, 0

.org 0x33000
  .quad 0x0000000000054003
  .fill 511, 8, 0

.org 0x34000
  .quad 0x0000000000033003
  .fill 511, 8, 0

.section .text
.code32
.global _start
_start:
  mov $0x10, %ax
  mov %ax, %ds

  lgdt gdtr

  mov $0x32000, %edi
  mov $0x33000+3, %eax

1:
  stosl
  mov $0x3f8, %dx
  add $4, %edi

  cmp $(0x32000+31*8), %edi
  jle 1b

  mov $0x33000, %edi
  mov $0x0+3, %eax

2:
  stosl
  add $0x1000, %eax
  add $4, %edi

  cmp $(0x33000+512*8*32-8), %edi
  jle 2b

// PAE
  mov %cr4, %eax
  btsl $5, %eax
  mov %eax, %cr4

// CR3
  movl $0x30000, %eax
  movl %eax, %cr3

// 64 mode
  mov $0xc0000080, %eax
  rdmsr
  bts $8, %eax
  bts $0, %eax
  wrmsr

  mov %cr0, %eax
  bts $31, %eax
  mov %eax, %cr0

// long jump
  ljmp $0x8, $0x100000