#include <iostream>


void RemoveDups( char* str )
{
//    char* end = str;
//    for( ; *end != '\0'; ++end);
//    int str_len = end - str;

    char* temp = str;
    char* write = temp;
    for(char* read = temp + 1; *read != '\0'; ++read) {
        if(*read != *write)
            *++write = *read;
    }
    *++write = '\0';

    str = temp;
}

int main(int argc, char *argv[])
{
    char* str = argv[1];
    RemoveDups( str );
    std::cout << str << std::endl;
    return 0;
}
