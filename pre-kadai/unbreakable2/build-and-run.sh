#!/bin/sh
gcc -O3 -o unbreakable2 unbreakable2.c || exit
strip -s unbreakable2

echo -ne "k|H$" > vivi
echo 'Oh~~ no~~, broked again (>_<) ' > flag
echo 'flag is flag{do not reuse Initialization vector}. ' >> flag
echo -n 'Good Job (*_*)' >> flag

echo '% echo -n "angr is awesome" | ./unbreakable2 $(cat vivi) | xxd'
echo -n "angr is awesome" | ./unbreakable2 $(cat vivi) | xxd

echo '% ./unbreakable2 $(cat vivi) < flag > encrypted_flag'
./unbreakable2 $(cat vivi) < flag > encrypted_flag