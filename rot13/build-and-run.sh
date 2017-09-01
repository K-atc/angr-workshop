#!/bin/sh
BIN="./rot13"
gcc -O3 -o $BIN "${BIN}.c" || exit
"${BIN}"