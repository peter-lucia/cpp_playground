#!/bin/zsh

mkdir -p cmake-build-debug
cd cmake-build-debug
cmake .
make help
make mytest VERBOSE=1
