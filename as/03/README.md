立即数寻址
---

有些指令的操作数是立即数，对于这种情况，x86直接将其编码在指令中，这种方式不需要额外访问寄存器和内存，寻址速度是最快的

并不是每条指令的操作数都含有立即数，所以其是机器指令的一个可选字段