ISSUE
---

新手上车踩坑

- 1 ssh到linux执行`glxinfo`检测OpenGL版本

- 2 gdk_monitor_get_scale_factor

  ![](./img/1710378915.png)

上面两个问题本质都是x11转发问题，在网上看到的解决方案是通过`VirtualGL`

[配置参考官方手册](https://rawcdn.githack.com/VirtualGL/virtualgl/3.0/doc/index.html#hd006)

配置方式过于复杂