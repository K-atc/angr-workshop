#!/bin/sh
BIN="./usage"
gcc -O3 -o $BIN "${BIN}.c" || exit
"${BIN}" guess_argv[2]_haha 000070