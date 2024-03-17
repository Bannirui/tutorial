#!/bin/sh

rm -rf build ;

cmake \
-G "Unix Makefiles" \
-S . \
-B build \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_C_COMPILER="/usr/local/Cellar/gcc@12/12.3.0/bin/gcc-12" \
-DCMAKE_CXX_COMPILER="/usr/local/Cellar/gcc@12/12.3.0/bin/g++-12"