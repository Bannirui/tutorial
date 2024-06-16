// 32位保护模式
# 数据段
.section .data


# 代码段
.section .text
.code32

.globl _start
_start:
  # 内核数据段描述符在全局段描述符表中 因此T1=0
  # 内核数据段位于全局段描述符表的第3项 所以为2 二进制10
  # 内核数据段的特权级为0
  # 因此内核数据段选择子的二进制值为10000 十六进制为0x10
  # 指令mov不支持将立即数写入段寄存器 先写入寄存器AX 再通过AX写入段寄存器
  mov $0x10, %ax
  mov %ax, %ds
  mov %ax, %es
  mov %ax, %fs
  mov %ax, %gs
  mov %ax, %ss

  # 重新装载段寄存器GDTR
  lgdt gdt

  # 通过一段循环填充二级页表项的内容
  # 把二级页表的基址存到寄存器EDI中 准备通过循环写数据到内存中 也就是填充页表项
  mov $0x32000, %edi
  # 二级页表的页表项1的值是0x33003
  mov $0x33000+3, %eax
# 标签标识循环体的开始
1:
  # stos的作用 在保护模式下 写4字节 stos指令将寄存器EAX中的值存储到内存地址ES:EDI中
  # 平坦模式下ES为0 因此sos就是将EAX寄存器中内容写到EDI寄存器中记录的地址上
  # 每写完一次 stos指令会将EDI寄存器中的值自动增加4个字节
  # 在32位模式下 操作数宽度为32 因此后缀l标识操作数的宽度是4字节
  stosl
  add $0x1000, %eax
  # 页表项的大小是8字节 stos的工作原理是写入完内存后自动给EDI寄存器增加4字节 因此再手动增加额外的4字节 让EDI寄存器中保存的地址指向下一个页表项
  add $4, %edi
  # 完成32个二级页表项的填充
  cmp $(0x32000+32*8-8), %edi
  jle 1b

  # 一级页表项的填充
  mov $0x33000, %edi
  mov $0x0+3, %eax
2:
  stosl
  add $0x1000, %eax
  add $4, %edi

  cmp $(0x33000+512*32*8-8), %edi
  jle 2b

  # setup direct-map level 2
  mov $0x56000, %edi
  mov $0x33000+3, %eax
3:
  stosl
  add $0x1000, %eax
  add $4, %edi

  cmp $(0x56000+32*8-8), %edi
  jle 3b

  # enable PAE
  xorl %eax, %eax
  # 指令bts用来设置位串中的某一位为1
  # 后缀l表示操作数是32位宽
  # bts不能直接操作控制寄存器cr4 所以先将cr4内容读到寄存器EAX 将第5位置为1 再将值写回控制寄存器
  btsl $5, %eax
  movl %eax, %cr4

  # x86设计了控制寄存器CR3 记录根页表的物理地址 当翻译地址时 内存管理单元从CR3中获取页表地址
  movl $0x30000, %eax
  movl %eax, %cr3

  # MSR寄存器EFER
  # 第0位 使能syscall指令
  # 第8位 使能64位模式
  # 第10位 激活64位模式
  # rdmsr指令用来读取MSR寄存器 rdmsr首先从ECX寄存器读出MSR寄存器地址 然后读取MSR的低32位到EAX中 读取高32位到EDX中
  # wrmsr指令用来写MSR寄存器 wrmsr首先从ECX寄存器读出MSR寄存器地址 然后将寄存器EAX内容写到MSR低32位 EDX内容写到MSR高32位
  # 指定MSR寄存器地址
  movl $0xc0000080, %ecx
  # MSR低32位内容读到EAX 高32位内容读到EDX
  rdmsr

  # MSR的第8位置1 就是使能64位模式
  btsl $8, %eax
  # MSR第0位置1 就是使能syscall指令
  btsl $0, %eax
  # EAX中改过的新置写回MSR寄存器
  wrmsr

  # 控制寄存器CR0 第31位使能开启分页
  xorl %eax, %eax
  # 使能CR0寄存器第31位 开启分页
  btsl $31, %eax
  # 使能CR0寄存器第0位
  btsl $0, %eax
  movl %eax, %cr0

  # 从保护模式进入64位模式
  # 经过这条指令后 指令指针寄存器RIP的值为 内核代码段的基址+$0x100000=0+0x100000=0x100000
  # 而内核映像的起始地址为0xffffffff80000000
  ljmp $0x8, $0x100000

gdt_start:
  .quad 0x0000000000000000
  .quad 0x00a09a0000000000
  .quad 0x00c0920000000000
gdt_end:

# 32位模式下 段基址是0 所以全局描述符表的地址就是gdt
gdt:
  # 段描述符表长度
  .word gdt_end-gdt_start
  # 分配8字节存储段描述符表的地址
  .quad gdt_start

# 64位模式下 linux将虚拟地址0xffffffff80000000映射到物理地址0
# 并将从0xffffffff80000000开始的512M空间用于映射物理内存中的内核映像

# 为保护模式部分预留64KB 然后开始分配四级页表
# 用伪指令.org定位到四级页表的基址处
.org 0x10000
# 四级页表
pml4:
  # 表项1 四级页表的页表项1指向三级页表0x53000
  .quad 0x0000000000053003
  # 表项2到表项273
  .fill 272, 8, 0
  # 表项274
  .quad 0x0000000000055003
  # 表项275到表项511
  .fill 237, 8, 0
  # 表项512
  .quad 0x0000000000031003

# 三级页表基址
.org 0x11000
# 三级页表
pml3:
  # 表项1到表项510
  .fill 510, 8, 0
  # 表项511
  .quad 0x0000000000032003
  # 表项512
  .fill 1, 8, 0

# 二级页表基址
.org 0x12000
# 二级页表
pml2:
  # 表项1
  .quad 0x0000000000033003
  # 表项2到表项512
  .fill 511, 8, 0

.org 0x13000
# pml1
pt:
  .fill 512*32, 8, 0

# id map
.org 0x33000
  .quad 0x0000000000054003
  .fill 511, 8, 0

.org 0x34000
  .quad 0x0000000000033003
  .fill 511, 8, 0

# linear map
# pml3
.org 0x35000
  .quad 0x0000000000056003
  .fill 511, 8, 0

# pml2
.org 0x36000
  .fill 32, 8, 0
  .quad 0x0000000000057003
  .fill 479, 8, 0

# pml1
.org 0x37000
  .fill 512, 8, 0
