#include <iostream>
#include <cstring>

struct Data
{
    char** vec;
    size_t number_strings;
};



size_t get_number_string(const char* general_string, char separator)
{
    size_t length = strlen(general_string);
    size_t number_strings = 0;
    for (size_t i = 1; i < length; i++) 
    {
        if(general_string[i] == separator)
        {
            if(general_string[i - 1] != separator)
                number_strings++;
        }
    }
    if(general_string[length - 1] != separator)
        number_strings++;

    return number_strings;
}



Data split(const char* general_string, char separator)
{
    Data data;
    data.vec = nullptr;
    data.number_strings = get_number_string(general_string, separator);
    
    size_t length = strlen(general_string);
    char buffer[length + 1];
    
    data.vec = new char*[data.number_strings]();
    
    size_t counter = 0;
    const char* left = general_string;
    const char* right = general_string;

    while(*right == separator) {
        right++;
    }
    left = right;

    while(*left != '\0' ) {
        if ((*right == separator || *right == '\0' ) && *left != separator) {
            int i = 0;
            for (; i < length && left != right; i++) {
                buffer[i] = *left;
                left++;
            }
            buffer[i] = '\0';
            
            char * str_i = new char[i + 1];
            strcpy(str_i, buffer);
            str_i[i+1] = '\0';
            auto im = counter++;
            data.vec[im] = str_i;

            while(*right == separator) {
                right++;
            }
            left = right;
        }
        right++;
    }

    return data;
}


void test(const char* general_string, char separator)        
{
    Data d = split(general_string, separator); 
    std::cout << d.number_strings << std::endl;
    for (size_t i = 0; i < d.number_strings; i++) {
        std::cout << d.vec[i] << std::endl;
    }

    std::cout << "---------------------------------"<< std::endl;
}


void test_c_cplit()
{
    test(" as s dsd dsd sd  123  sd", ' ');// Ok
    test(" as s dsd  ", ' ');//OK as s dsd
    test(" sddsds ",' ');//OK sddsds
    test("dasdads", ' ');// OK
    test("ab sd", ' ');//  ok
    test(" cf sd", ' ');// OK
    test(" gh sd ", ' ');//OK
    test("sd er ", ' ');//OK
}


