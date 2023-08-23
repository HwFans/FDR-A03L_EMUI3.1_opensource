#!/bin/bash

LOCAL_DIR=`pwd`
export PATH=$PATH:$LOCAL_DIR/tools/gcc/aarch64-linux-android-4.9//bin:$PATH

rm -rf ./out
mkdir -p out/KERNEL_OBJ
make -C kernel O=../out/KERNEL_OBJ ARCH=arm64 CROSS_COMPILE=aarch64-linux-android- msm_defconfig
make -C kernel O=../out/KERNEL_OBJ ARCH=arm64 CROSS_COMPILE=aarch64-linux-android- 