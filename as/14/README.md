栈传递参数
---

32位的x86调用规定，函数之间使用栈传递参数，如果函数有多个参数，那么调用函数从最后一个参数开始压栈，最后压第一个参数

被调用函数，可以以BP为锚点，从栈中取出参数，栈从高地址向低地址增长，因此对于16位x86，BP是当前函数栈帧基址，BP+2是返回地址，BP+4是第一个参数，即4(%bp)
