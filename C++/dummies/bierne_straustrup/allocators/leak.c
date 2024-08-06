#include <stdlib.h>

void leak(unsigned int n) {
    malloc(n);
}

int main(int argc, char** argv) {
    leak(1);
    leak(2);
    leak(3);

    void* m = malloc(1024);
    free(m);
    return 0;
}

