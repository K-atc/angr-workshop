Chapter 3. rand_master
====

Level: Medium Hard

Time: this may take 25 - 40 minutes

Contents
----
* review advanced reversing techniques
* review glibc's constructor/destructor
* how to hook function
* how to handle unpredictable variable value
* how to overwrite variable value
* how to symbolize variable

Exercise
----
Download [rand_master](./rand_master). 
Analyze the binary and answer the following questions.
Flag format is `angr{***}`.

(1) If run `./rand_master`, what happens? Do the binary exepects any user inputs? (1 min)

(2) Disable `rand()` using dinamic link libraly (please name it as `librand.so`). (5 min)

(3) What is flag? How is the flag crafted? (4 - 14 min)

(4) Write solver script using angr. (15 - 20 min)

Hints
----
### (1)
JUST DO IT!!

### (2)
Remember `LD_PRELOAD` :)

Runnig `man 8 ld.so` is helpful.

### (3)
#### Hint 1
Getting flag is easy. But crafting flag steps are tricky.

#### Hint 2
Find 4 keys named `key1`, `key2`, `key3`, `key4`.

#### Hint 3
`objdump -Mintel -s -d rand_master` may halps you

#### Hint 4
see definition of:

* [__libc_csu_init](https://github.com/lattera/glibc/blob/master/csu/elf-init.c#L105)
* [_dl_fini](https://github.com/lattera/glibc/blob/a2f34833b1042d5d8eeb263b4cf4caaea138c4ad/elf/dl-fini.c#L131)

#### Hint 5
Take care about Little Endian

### (4)
#### Hint 1
https://github.com/angr/angr-doc/blob/master/CHEATSHEET.md#ffi-and-hooking

#### Hint 2
recommended analysis steps:

1. make `rand()` `int rand(){return 0}`
2. make variable `r` in `main` symbol variable
3. set `print_flag` as find_addr
4. set avoid_addr in main
5. concrete stdout -> you get flag!!