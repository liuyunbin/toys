#!/bin/bash

set -eux

INSTALL_DIR=$(pwd)
LIBEVENT=libevent-2.1.12-stable

cd third-party/libevent

rm -rf libevent

tar xvf ${LIBEVENT}.tar.gz

mv  ${LIBEVENT} libevent

cd libevent

mkdir -p build

cd build

cmake .. -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
         -DEVENT__DISABLE_OPENSSL=ON \
         -DEVENT__LIBRARY_TYPE=STATIC

make

make install

