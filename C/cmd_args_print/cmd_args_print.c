#include <stdio.h> 

int main(int argc, char **argv) // pointer to pointer
{
    argv ++;
    while(*argv)
    {
        printf("[%s]\n", *argv);
        argv++;
    }
    return 0;
}
