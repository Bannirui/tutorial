#!/bin/sh

cmake \
    -G "Unix Makefiles" \
    -S . \
    -B build \
    -DCMAKE_VERBOSE_MAKEFILE=ON