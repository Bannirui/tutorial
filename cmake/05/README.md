项目可能需要依赖三方库，使用`git submodule`的方式

以`zlog`为例演示

```shell
cd tutorial

git submodule add git@github.com:HardySimpson/zlog.git cmake/05/external/zlog

git commit -am "msg"
```

后续需要更新三方库的时候可能还要在根目录下手动执行

```shell
git submodule update --init --recursive
```

很多时候终端执行命令需要频繁的切换目录，这种比较繁琐的操作要么使用cmake-gui替代，要么使用shell脚本

linux command line ez mode

```shell
./configure.sh
./build.sh
./run.sh
```

当前方式总体而言可用但不优雅，下一章节尝试完全托管给cmake来管理