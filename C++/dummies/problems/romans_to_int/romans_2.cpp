//more readable, but worst on runtime

#include <string>
//#include <stdio.h>
#include <iostream>


using std::string;

class Solution {
public:
    int romanConverter( char c );
    int romanToInt( string s );
};

int Solution::romanConverter( char c ) {
    switch( c )
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default : return 0;
    }
}

int Solution::romanToInt( string s ) {
    int result = 0;
    short num_last = 0;
    short num_this = 0;
    for ( int i = s.size() -1; i >= 0; i-- ) {
        num_this = romanConverter( s[i] );
        num_this < num_last?  result -= num_this: result += num_this;
        num_last = num_this;
    }

    return result;
}

int main( int argc, char **argv)
{
    string roman_num = argv[1];
    Solution solver;
    int arabic = solver.romanToInt( roman_num );
    std::cout << arabic << std::endl;
    return  0;
}
