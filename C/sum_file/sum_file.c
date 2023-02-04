#include <stdio.h>


void intfilesum( FILE *file_ptr, int *sum, int *count );

int main(int argc, char **argv)
{   
    FILE *file_ptr;
    int sum, count;
    file_ptr =  fopen(argv[1], "r");
    intfilesum(file_ptr, &sum, &count);
    printf( "%d %d", sum, count );
    
    return 0;
}

void intfilesum( FILE *file_ptr, int *sum, int *count )
{
    int n;
    *count = 0;
    *sum = 0;

    while(fscanf(file_ptr, "%d", &n) == 1){
        *sum += n;
        (*count)++;
    }
}
