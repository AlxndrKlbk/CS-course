#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePtr;
    filePtr = fopen("file.txt", "r+");
    if (!filePtr){
        perror("file.txt");
        exit(1);
    }
}

