#include <stdio.h>


int string_length(const char *str)
{
    const char *p;
    for( p=str; *p; p++ )
        {}
    return p - str;
}

void string_copy(char *dest, const char *src)
{
    int i;
    for(i=0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
}

int main()
{   
    int len;
    char str[] = "some string";
    len = string_length(str);
    printf("string '%s' contain %d characters\n", str, len); 
    return len;
}
