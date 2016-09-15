#!/bin/bash

mkdir -p /mnt/appimager/build
cp -R /mnt/appimager/usr /mnt/appimager/build

gcc loopmounter.c -o /mnt/appimager/build/usr/bin/loopmounter
strip /mnt/appimager/build/usr/bin/loopmounter

chown root:root /mnt/appimager/build/usr/bin/loopmounter
chmod 4755 /mnt/appimager/build/usr/bin/loopmounter

rm -f 0.9.42.tar.gz
wget https://github.com/netblue30/firejail/archive/0.9.42.tar.gz
tar xf 0.9.42.tar.gz
cd firejail-0.9.42

./configure --prefix=/mnt/appimager/build/usr
make
make install

cd ..

rm -rf firejail-0.9.42 0.9.42.tar.gz
