#include <iostream>


void RemoveDups(char* str )
{
    char* write = str;
    for(char* read = str + 1; *read != '\0'; ++read) {
        if(*read != *write) {
            *++write = *read;
        }
    }
    *++write = '\0';
}

int main(int argc, char *argv[])
{
    char* str = argv[1];

    std::cout << "init str : " << str << std::endl;
    RemoveDups( str );
    std::cout << "filterd : " << str << std::endl;
    return 0;
}
