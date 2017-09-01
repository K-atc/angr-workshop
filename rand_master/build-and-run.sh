#!/bin/sh
BIN="./rand_master"
gcc -shared rand.c -o librand.so
gcc -masm=intel -o $BIN "${BIN}.c" || exit
# objdump -d $BIN > "${BIN}.att.S"
objdump -Mintel -d $BIN > "${BIN}.S"

readelf -s $BIN > "${BIN}.sections"
objdump -Mintel -s -d $BIN > "${BIN}.all.S"
objdump -Mintel -s -j .init_array -d $BIN > "${BIN}.init_array.S"

echo "% ${BIN}"
"${BIN}"

echo "% LD_PRELOAD=./librand.so ${BIN}"
# LD_PRELOAD=./librand.so ldd "${BIN}"
LD_PRELOAD=./librand.so "${BIN}"

if [ -f .[0-9]* ]; then
    rm .[0-9]*
fi