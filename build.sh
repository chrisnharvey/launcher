#!/bin/bash

mkdir -p /mnt/appimager/build
cp -R /mnt/appimager/usr /mnt/appimager/build

rm -f 0.9.42.tar.gz
wget https://github.com/netblue30/firejail/archive/0.9.42.tar.gz
tar xf 0.9.42.tar.gz
cd firejail-0.9.42

./configure --disable-globalcfg --prefix=/mnt/appimager/build/usr
make
make install

cd ..

rm -rf firejail-0.9.42 0.9.42.tar.gz
