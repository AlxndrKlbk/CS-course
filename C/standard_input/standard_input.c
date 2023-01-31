#include <stdio.h>

int main()
{
    int c, pr;
    pr = 1;

    while((c = getchar()) != EOF){
        switch(c){
            case '\n':
                putchar('\n');
                pr = 1;
                break;
            case ' ':
                pr = 0;
                break;
            default:
                if(pr)
                    putchar(c);
        }
    }
    return 0;

}
