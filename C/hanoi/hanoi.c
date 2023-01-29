#include <stdio.h>
#include <stdlib.h> // for atoi

static void solve(int source, int target, int interm, int n)
{
    if(n == 0)
        return;

    solve(source, interm, target, n-1);
    printf("%d: %d -> %d\n", n, source, target);
    solve(interm, target, source, n-1);
}

int main(int argc, char **argv)
{
    int n;
    if(argc < 2){
        fprintf(stderr, "No parameter given\n");
        return 1;
    }
    n = atoi(argv[1]);
    if(n < 1){
        fprintf(stderr, "Incorrect token count\n");
        return 2;
    }
    solve(1, 3, 2, n);
    return 0;
}
