寄存器传递参数
---

除了使用栈传递参数，也可以使用寄存器传递参数

64位x86相比32位增加了8个通用寄存器，显然寄存器传参要比内存传参高效，所以x86调用约定规定64位模式下依次使用寄存器rdi、rsi、rdx、rcx、r8-9传递参数
