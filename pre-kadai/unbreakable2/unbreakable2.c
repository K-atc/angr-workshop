#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

#define f(x) (iv_str[x] << x * 8)
#define SHIFT 2

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return -1;
    }

    char *iv_str = argv[1];
    uint32_t iv = f(3) + f(2) + f(1) + f(0);
    // printf("%x\n", iv);
    // return 0;
    char c = fgetc(stdin);
    while (c != EOF) {
        iv = (iv << SHIFT) | (iv >> (32 - SHIFT));
        // printf("(char) iv = %x\n", (unsigned char) iv);
        char k = (unsigned char) iv ^ c;
        printf("%c", k);
        // printf("%x\n", iv);
        c = fgetc(stdin);
    }

    return 0;
}