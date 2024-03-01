#!/bin/sh

# 先删除构建目录
if [ -d "../build" ];then
    rm -rf ../build
fi

cmake \
    -G "Unix Makefiles" \
    -S . \
    -B ./../build