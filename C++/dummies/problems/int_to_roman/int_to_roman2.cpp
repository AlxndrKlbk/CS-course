#include <string>
#include <iostream>

using std::string;
using std::cout, std::endl;

class Solution {
public:
    string intToRoman(int num) {

        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for(int i = 0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }

        return res;

    }
};

int main( int argc, char** argv)
{
    Solution solver = Solution();
    int value = std::atoi( argv[1] );
    cout << solver.intToRoman( value ) << endl;
    return 0;
}
