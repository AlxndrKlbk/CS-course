#include <stdio.h>

int startmatch(const char *str, const char *pat);

int match(const char *str, const char *pat)
{
    switch(*pat){
        case 0:
            return *str == 0;
        case '?':
            if(!*str)
                return 0;
            return match(str+1, pat+1);
        case '*':
            return startmatch(str, pat+1);
        default:
            if(*str != *pat)
                return 0;
            return match(str+1, pat+1);
    }
}

int startmatch(const char *str, const char *pat)
{
    int i;
    for(i=0; ; i++){
        int res = match(str + i, pat);
        if(res)
            return 1;
        if(!str[i])
            return 0;
    }
}

int main(int argc, char **argv)
{   
    char *str = argv[1];
    char *pattern = argv[2];
    printf("%d\n", startmatch(str, pattern));
    return 0;
}
