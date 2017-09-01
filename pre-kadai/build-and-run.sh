#!/bin/sh
gcc -O3 -o unbreakable unbreakable.c || exit
nm unbreakable > unbreakable.syms
strip -s unbreakable

echo "% echo -n 'test' > 'test.txt'"
echo -n 'test' > 'test.txt'
echo "% ./unbreakable key test.txt"
./unbreakable key test.txt
echo ""

echo "% ./unbreakable key flag > cipher.txt"
./unbreakable key flag > cipher.txt