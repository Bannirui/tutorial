// 64位模式

.section .text
.code64

.global _start
.global gdt
.global ret_from_kernel
.global task0_stack
.global idle_task_entry

_start:
  lgdt gdtr
  lidt idtr

  // setup seg
  mov $KERNEL_DS, %ax
  mov %ax, %ds
  mov %ax, %es
  mov %ax, %fs
  mov %ax, %gs
  mov %ax, %ss

  # setup stack
  mov %task0_stack, %rsp

  push $main
  ret

gdt:
  # reserved
  .quad 0x0000000000000000
  # kernel cs
  .quad 0x00209a0000000000
  # kernel ds
  .quad 0x0000920000000000
  # user32 cs
  .quad 0x0000000000000000
  # user ds
  .quad 0x0000f20000000000
  # user64 cs
  .quad 0x0020fa0000000000
  .fill 64-6, 8, 0
gdt_end:

gdtr:
  .word gdt_end-gdt
  .quad gdt

idtr:
  .word 16*256
  .quad idt_table

// 4kb
.fill 4096, 1, 0

task0_stack:

ret_from_kernel:
  mov $USER_DS, %rax
  movw %ax, %ds
  movw %ax, %es
  movw %ax, %fs
  movw %ax, %gs
  iretq

idle_task_entry:
1:
  sti
  hlt
  jmp 1b