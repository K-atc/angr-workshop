#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
>>> "as_"[::-1].encode("hex")
'5f7361'
>>> "runtime_security"[::-1].encode("hex")
'79746972756365735f656d69746e7572'
*/
// #define KEY1 0x75636573
#define KEY1 0x5f7361
#define KEY2 0x7974697275636573
#define KEY3 "0x746e7572"
#define KEY4 "0x5f656d69"

long int key1;
long int key2;
long int key3;
long int key4;

char flag_format[] = "angr{may_not_use_rand_%s%s%s%s}\n";

void int_to_string(long int int_str, char* str, size_t size)
{
    for (int i = 0; i < size; i++) {
        int shift = 8 * (size - i);
        str[i] = ((char *) &int_str)[i];
    }
    str[size] = 0;
    // puts(str);
}

// fini_array call (1)
__attribute__((destructor, section(".text")))
void print_flag()
{
    char buf1[9], buf2[9], buf3[9], buf4[9];
    int_to_string(key1, buf1, 8);
    int_to_string(key2, buf2, 8);
    int_to_string(key3, buf3, 8);
    int_to_string(key4, buf4, 8);
    printf(flag_format, &buf1, &buf3, &buf4, &buf2);
}

__attribute__((constructor, section(".text")))
void __init()
{
    key2 = KEY2;
}

// fini_array call (2)
__attribute__((destructor, section(".text")))
void __fini()
{
    __asm__(
        // "mov rax, qword ptr [rsp];"
        "mov rax, qword ptr [r13];"
        "and rax, 0xfffffffffffff000;"
        "add rax, 0x101000;"
        "add rax, 0x1000c0;"
        // "mov qword ptr [rax], 0x7974697275636573;"
        "mov qword ptr [rax], " KEY3 ";"
        "add rax, -16;"
        "mov qword ptr [rax], " KEY4 ";"
        );
    // printf("[__fini] key3 = %x\n", key3);
}

int main()
{
    srand((unsigned)time(NULL));
    long int r = rand();
    // printf("sizeof(long long int) = %d\n", sizeof(long long int));
    // printf("RAND_MAX = %d\n", RAND_MAX);
    // printf("r = %lx\n", r);
    // r = KEY1;
    if (r != KEY1) {
        puts("you have no chance. re-try!");
        flag_format[0] = 0;
        return -1;
    }
    key1 = r;
}