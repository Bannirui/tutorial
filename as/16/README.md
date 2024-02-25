局部变量
---

函数运行时，经常需要使用一些内存来存放临时数据，这些内存在函数执行完毕后也需要释放

因为这些内存区域中的变量仅函数自己可见，所以，相对全局变量，这些变量称为局部变量

根据局部变量的生命周期可见，将其分配在函数的栈帧上再合适不过

x86调用约定规定在压栈主调函数的栈帧基址后，在栈上为函数分配局部变量所需要的空间