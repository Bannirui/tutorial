# 伪指令 告知编译器接下来是代码段
.text

# 伪指令 告知编译器生成16位汇编代码
.code16

# kvmtool段寄存器的默认值是0x1000
# 标签 标识程序的起始位置
start:
  # mov不支持将立即数直接写到段寄存器中 用AL寄存器中转
  mov $0x1010, %bx
  mov %bx, %es

  # 0x3f8这个串口地址大于256 不能用立即数形式 所以先装载到寄存器DX
  mov $0x3f8, %dx

  # 源操作数是0x100 没有$前缀 说明不是立即数
  # 汇编器会将不是$开头的数字看作一个内存地址
  # kvmtool初始化的数据段寄存器DS的段基址=0x1000
  # mov指令把内存地址DS<<4+0x100=0x10100处读取到的数据放到寄存器AL中
  # 处理器在内存上读取多大的数据 AL是8位 因此读取8bit的数据 1个byte
  # 也就是字符B装载到寄存器AL中
  mov 0x100, %al

  # 向串口发起写操作 AL寄存器中字符B写到外设地址0x3f8
  out %al, %dx

  # ES<<4+0x100=0x10200上的1个Byte内容装载到寄存器AL 也就是把'C'装载到AL
  # 显式指定段寄存器ES
  mov %es:0x100, %al
  
  # 向串口发起写操作 AL
  out %al, %dx

  # 程序执行完毕 告诉处理器停止运行
  hlt

  # 代码段基址相对偏移处放2个byte的内容
  # CS默认值0x1000
  # CS:0x100=0x10100 放字符B
  .org 0x100
    .byte 0x42

  # CS:0x200=0x10200 放字符C
  .org 0x200
    .byte 0x43