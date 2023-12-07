#!/bin/sh

cmake \
-DUSE_ADDER=OFF \
-DTEST_FILE=ON \
-DTEST_ADDER=ON \
-DTEST_ZLOG=ON \
-S . -B out/build