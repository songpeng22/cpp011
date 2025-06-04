#!/bin/bash
# CMake build
rm -rf build
mkdir -p build
pushd build
cmake ../src 
make #or make VERBOSE=1
cp APITest liblogTest.so ../ -v 
popd

# Makefile build
#pushd src
#make
#popd
#mv src/main . -v
#pwd
