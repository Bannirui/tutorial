// 64位模式

#include "include/segment.h"

.section .text
.code64

.global _start
.global gdt
# 0号任务
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
  mov $task0_stack, %rsp

  # push指令支持符号位扩展
  # push $main 语义是压栈符号main的地址
  # push main 语义是将内存地址main处的内容压栈
  # 64位模式下push的操作数宽度是64位 当压栈的源操作数是32位时 push指令会用符号位填充压栈的64位中的高32位
  push $main
  # 执行ret指令时 64位地址会被弹出到RIP指令寄存器中
  # 通过push和ret巧妙结合可以将符号位置1
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