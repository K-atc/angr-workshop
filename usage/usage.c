#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE usage(argv)

int calc_check_digit(char* num_str)
{
    int check_digit = 0;
    char c;
    for (int i = 0; i < 5; i++) {
        c = num_str[i];
        check_digit += atoi(&c);
    }
    // printf("check_digit = %d\n", check_digit);
    return check_digit % 10;
}

void usage(char* argv[])
{
    printf("usage: %s ???", argv[0]);
}

void print_flag()
{
    FILE *fp;
    fp = fopen("flag", "r");
    if (!fp) {
        perror("cannot open flag. tell admin about it");
        return;
    }
    char buf[128];
    fgets(buf, 128, fp);
    puts(buf);
    fclose(fp);
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        USAGE;
        return 1;
    }
    if (strncmp(argv[1], "guess_argv[2]_haha", 18)) {
        USAGE;
        return 1;
    }
    if (strlen(argv[2]) != 6 || calc_check_digit(argv[2]) != 7) {
        USAGE;
        return 1;
    }
    print_flag();
    return 0;
}