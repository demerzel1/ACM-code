//WINDOWS
extern int main2(void) __asm__ ("_main2");

int main2() {
    char test[255 << 20];
    memset(test, 42, sizeof(test));
    printf(":)\n");
    exit(0);
}

int main() {
    int size = 256 << 20;  // 256Mb
    char *p = (char *)malloc(size) + size;
    __asm__ __volatile__(
        "movl  %0, %%esp\n"
        "pushl $_exit\n" 
        "jmp _main2\n"
        :: "r"(p));
}
//LINUX
extern int main2(void) __asm__ ("main2");

int main2() {
    char test[255 << 20];
    memset(test, 42, sizeof(test));
    printf(":)\n");
    exit(0);
}

int main() {
    int size = 256 << 20;  // 256Mb
    char *p = (char *)malloc(size) + size;
    __asm__ __volatile__(
        "movq  %0, %%rsp\n"
        "pushq $exit\n" 
        "jmp main2\n"
        :: "r"(p));
}