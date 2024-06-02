// 16位实模式

# 数据段
.section .data

#define IO_PIC     0x20
#define IRQ_OFFSET 32

# 代码段
.section .text
.code16

// 1 创建保护模式的段描述符文表
// 2 告知处理器段描述符表地址
// 3 开启处理器保护模式
// 4 跳转到内核保护模式

.global _start

_start:
  # 关闭中断
  cli

  # read e820
  mov $e820_entry, %di
  # 设置ebx为0
  xor %ebx, %ebx

e820_rd_entry:
  mov $0xe820, %eax
  mov $20, %ecx
  int $0x15

  add $20, %di
  incb e820_nr_entry

  cmp $0, %ebx
  jne e820_rd_entry

  # get display mode info
  mov $vesa_mode_info, %di
  mov $0x4f01, %ax
  int $0x10

  # Init 8259A
  # ICW1
  mov $0x13, %al
  mov $(IO_PIC), %dx
  out %al, %dx
  # ICW2
  mov $(IRQ_OFFSET), %al
  mov $(IO_PIC+1), %dx
  out %al, %dx
  # ICW4
  mov $0x1, %al
  mov $(IO_PIC+1), %dx
  out %al, %dx

  # x86处理器提供了专用指令ldgt从内存中加载段描述符表地址到寄存器GDTR
  # 47          16 15           0
  # [段描述符地址][段描述符表长度]
  lgdt gdtr

  # 准备好段描述符表之后就可以开启保护模式了 处理器中控制寄存器CR0第0位PE用于控制处理器是否开启保护模式
  mov %cr0, %eax
  or $0x1, %eax
  mov %eax, %cr0

  # ljmpl接收2个操作数
  # 第一个操作数是段选择子 0000000000001 0 00
  # 第二个操作数是段内偏移地址 保护模式的入口地址是0x20000 段基址是0 所以段内偏移是x020000
  ljmpl $0x8, $0x20000

# 创建保护模式的段描述符表
gdt:
    # quad伪指令向当前内存位置写入64位整数值
    # 段描述符表的每个表项64bit 8byte
    # x86处理器约定段描述符表的第0项保留不用 所以将第0项设置为0
    .quad 0
    # 第1项定义内核代码段 用的是平坦模型 段基址是0
    .quad 0x00c09a00000007ff
    # 第2项定义内核数据段
    .quad 0x00c09200000007ff
gdt_end:

# 定义48位的变量 高32位存放段描述符表的地址 低16位存放段描述符表的长度(段描述符表有多少个byte)
gdtr:
    # 低16位 数组大小
    .word gdt_end - gdt
    # DS=0x1000 偏移=gdt
    # 那么段描述符表的地址=DS<<4+gdt=0x10000+gdt 总共就20位 高4位是0x1 低16位是gdt
    # 中间16位
    .word gdt
    # 高16位
    .word 0x01

# e820map
.org 0x3000
e820_nr_entry:
  .long 0
e820_entry:
  .fill 512, 1, 0

# vesa mode info
.org 0x4000
vesa_mode_info:
  .fill 256, 1, 0