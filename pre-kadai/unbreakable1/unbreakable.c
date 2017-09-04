#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum load_err {
    FILE_OK = 0,
    FILE_NOT_EXISTS,
    FILE_FORMAT_ERR
};

// void hex_dump(char *hex, size_t size)
// {
//     for (int i = 0; i < size; i++) {
//         printf("%02x ", (unsigned char) hex[i]);
//         if (i && ((i + 1) % 16 == 0)) {
//             printf("\n");
//         }
//     }
//     if (size % 16) {
//         printf("\n");
//     }    
// }

enum load_err load_file(char *file_name, char *buf, int (* validate)(int))
{
    FILE *fp;
    fp = fopen(file_name, "r");
    if (!fp) {
        return FILE_NOT_EXISTS;
    }
    while (!feof(fp)) {
        char c = fgetc(fp);
        if (c == -1) {
            break;
        }
        if (validate(c)) {
            *(buf++) = c;
        }
        else {
            return FILE_FORMAT_ERR;
        }
    }
    return FILE_OK;
}

void encrypt(char *plain, char *cipher, char *key, size_t size)
{
    memset(cipher, 0, size);
    for (int i = 0; i < size; i++) {
        cipher[i] = plain[i] ^ key[i];
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return -1;
    }

    char *key_file = argv[1];
    char *plain_file = argv[2];
    char key[1024];
    char plain[1024];
    char cipher[1024];
    enum load_err err;
    memset(key, 0, 1024);
    err = load_file(key_file, key, isdigit);
    if (err) {
        // perror("key error");
        return -1;
    }
    memset(plain, 0, 1024);
    err = load_file(plain_file, plain, isprint);
    if (err) {
        // perror("plain error");
        return -1;
    }    
    memset(cipher, 0, 1024);
    encrypt(plain, cipher, key, strlen(plain));
    fputs(cipher, stdout);

    // encrypt(cipher, plain, key, strlen(plain));
    // puts(plain);
    return 0;
}