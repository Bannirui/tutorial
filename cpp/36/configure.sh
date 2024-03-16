#!/bin/sh

rm -rf build ;

cmake \
-G "Unix Makefiles" \
-S . \
-B build \
-DCMAKE_BUILD_TYPE=Debug