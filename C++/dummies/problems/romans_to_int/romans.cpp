#include <stdio.h>
#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    static void addPrev( int& num, char* chr )
    {
        if( *chr == 'I')
            num += 1;
        else if( *chr== 'X' )
            num += 10;
        else if ( *chr == 'C' )
            num += 100;
    }

    static int romanToInt(string s) {
        int num = 0;
        char* prev = nullptr;

        for( auto& chr : s)
        {
            if( prev )
            {
                if( *prev == 'I' && ( ( chr == 'X' || chr == 'V' ) || chr == 'I' ) )
                {
                    if (chr == 'X')
                        num += 9;
                    else if( chr == 'V' )
                        num += 4;
                    else
                    {
                        num += 1;
                        continue;
                    }
                    prev = nullptr;
                    continue;
                }
                else if( *prev == 'X' && ( ( chr == 'L' || chr == 'C' ) || chr == 'X' ) )
                {
                    if (chr == 'L')
                        num += 40;
                    else if( chr == 'C' )
                        num += 90;
                    else
                    {
                        num += 10;
                        continue;
                    }
                    prev = nullptr;
                    continue;
                }
                else if( *prev == 'C' && ( ( chr == 'D' || chr == 'M' ) || chr == 'C' ) )
                {
                    if (chr == 'D')
                        num += 400;
                    else if( chr == 'M' )
                        num += 900;
                    else
                    {
                        num += 100;
                        continue;
                    }
                        prev = nullptr;
                    continue;
                }

                addPrev( num, prev );
            }

            if( chr == 'I' || chr == 'X' || chr == 'C' )
            {
                prev = &chr;
                continue;
            }
            else if( chr == 'V' )
            {
                prev = nullptr;
                num += 5;
            }
            else if( chr == 'L' )
            {
                prev = nullptr;
                num += 50;
            }
            else if( chr == 'D' )
            {
                prev = nullptr;
                num += 500;
            }
            else if( chr == 'M' )
            {
                prev = nullptr;
                num += 1000;
            }

        }

        if( prev )
            addPrev( num, prev );
        return num;
    }
};

int main( int argc, char **argv)
{
    string roman_num = argv[1];
    int arabic = Solution::romanToInt( roman_num );
    std::cout << arabic << std::endl;
    return  0;
}
