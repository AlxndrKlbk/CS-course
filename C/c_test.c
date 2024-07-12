#include <stdio.h>

int main()
{
    char m[] = "mt_string";
    char* m_ptr = m;
    printf("\n");

    printf("%s", m);
    printf("\n");

    *(m_ptr + 1) = 'y';

    printf("%s", m);
    printf("\n");

    return 0;
}
