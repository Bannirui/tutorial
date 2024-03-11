// 加了static修饰 链接器在全局作用域就找不到这个符号了
// 相当于作用于限制在当前文件
int val = 6;

static int s_Val = 5;