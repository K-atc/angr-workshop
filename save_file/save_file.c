#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>

#define E "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637721112523897844250569536967707854499699679468644549059879316368892300987931277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684161403970198376793206832823764648042953118023287825098194558153017567173613320698112509961818815930416903515988885193458072738667385894228792284998920868058257492796104841984443634632449684875602336248270419786232090021609902353043699418491463140934317381436405462531520961836908887070167683964243781405927145635490613031072085103837505101157477041718986106873969655212671546889570350354"

#define SAVE_FILE_NAME "saved_state"
#define CURRENT_VERSION_MAJOR 3
#define CURRENT_VERSION_MINOR 14
#define MINIMUM_VERSION_MAJOR 3
#define MINIMUM_VERSION_MINOR 1

struct state {
    uint32_t version_major;
    uint32_t version_minor;
    uint64_t pos;
    void (*call)();
    uint64_t call_offset;
} state;

int main();

void handle_sigint(int signo)
{
    exit(1);
}

__attribute__((constructor, section(".text")))
void load_state()
{
    FILE *fp;
    fp = fopen(SAVE_FILE_NAME, "r");
    if (!fp) {
        perror("[!] cannot open save file. using default state");
        state.version_major = CURRENT_VERSION_MAJOR;
        state.version_minor = CURRENT_VERSION_MINOR;
        state.pos = 0;
        state.call = NULL;
        return;
    }
    fread((void *) &state, sizeof(state), 1, fp);
    bool version_check_passed = false;
    if (state.version_major == MINIMUM_VERSION_MAJOR && 
        state.version_minor >= MINIMUM_VERSION_MINOR) {
        version_check_passed = true;
    }
    else if (state.version_major > MINIMUM_VERSION_MAJOR) {
        version_check_passed = true;
    }
    if (!version_check_passed) {
        fprintf(stderr, "[!] version check failed. exit.\n");
        exit(1);
    }
    uint64_t base_addr = (uint64_t) main & (uint64_t) ~0xfff;
    // printf("base_addr = %lx\n", base_addr);
    if (state.call_offset) {
        state.call = (void (*)()) (base_addr + state.call_offset);
    }
    // printf("state.call = %lx\n", (uint64_t) state.call);
    fclose(fp);
}

__attribute__((destructor, section(".text")))
void save_state()
{
    FILE *fp;
    fp = fopen(SAVE_FILE_NAME, "w");
    if (!fp) {
        perror("[!] cannot open save file. exit");
        exit(1);
    }
    uint64_t base_addr = (uint64_t) main & (uint64_t) ~0xfff;
    if (state.call) {
        state.call_offset = (uint64_t) state.call - base_addr;
    }
    else {
        state.call_offset = 0;
    }
    fwrite((void *) &state, sizeof(state), 1, fp);
    fclose(fp);
}

void print_flag()
{
    FILE *fp;
    fp = fopen("flag", "r");
    if (!fp) {
        perror("[!] cannot open flag. tell admin about it");
        exit(1);
    }
    char buf[128];
    fgets(buf, 128, fp);
    puts(buf);
    fclose(fp);
    exit(1);
}

void print_dot()
{
    printf(".");
}

void print_0()
{
    printf("0");
}

void print_1()
{
    printf("1");
}

void print_2()
{
    printf("2");
}

void print_3()
{
    printf("3");
}

void print_4()
{
    printf("4");
}

void print_5()
{
    printf("5");
}

void print_6()
{
    printf("6");
}

void print_7()
{
    printf("7");
}

void print_8()
{
    printf("8");
}

void print_9()
{
    printf("9");
}

void fin()
{
    state.pos = 0;
    state.call = NULL;
    exit(0);
}

int main()
{
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("cannot handle SIGINT. exit");
        exit(1);
    }

    char text[1024] = E;
    int len = 1002;
    if (state.call) {
        state.call();
        state.pos++;
    }
    for (int i = state.pos; i < len; i++) {
        char c = text[i];
        switch (c) {
            case '.': state.call = print_dot; break;
            case '0': state.call = print_0; break;
            case '1': state.call = print_1; break;
            case '2': state.call = print_2; break;
            case '3': state.call = print_3; break;
            case '4': state.call = print_4; break;
            case '5': state.call = print_5; break;
            case '6': state.call = print_6; break;
            case '7': state.call = print_7; break;
            case '8': state.call = print_8; break;
            case '9': state.call = print_9; break;
            default: state.call = fin; break;
        }
        state.call();
        fflush(stdout);
        state.pos++;
        state.call = NULL;
        sleep(1);
    }
    state.pos = 0;
    fprintf(stderr, "\n[*] printing text finished!! reseted!!\n");
    return 0;
}