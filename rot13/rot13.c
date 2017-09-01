#include <stdio.h>
#include <ctype.h>
#include <string.h>

void trim(char* str)
{
    str[strlen(str) - 1] = 0; // erase `\n'
}

void rot13(char* str, size_t size)
{
    for (int i = 0; i < size; i++) {
        char c = str[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                str[i] = (c - 'A' + 13) % 26 + 'A';
            }
            else if (islower(c)) {
                str[i] = (c - 'a' + 13) % 26 + 'a';
            }
        }
    }
}

int main()
{
    char buf[1024];
    fgets(buf, 1024, stdin);
    trim(buf);
    rot13(buf, 1024);
    // puts(buf);
    if(strcmp(buf, "nate{ebg13_pvcure_vf_abg_fgebat_pvcure}"))
    {
        puts("incorrect");
    }
    else
    {
        puts("congratz!");
    }
}