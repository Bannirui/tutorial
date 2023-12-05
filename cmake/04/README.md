因为手动复制的诸多负面影响，库文件在编译的时候直接采用`make install`的方式

可惜的是在mac上

- `/usr/local/include`目录并不是默认的头文件搜索路径
- `/usr/local/lib`目录不是默认的链接库搜索路径
