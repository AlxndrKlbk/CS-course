#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::cout, std::endl;

class Solution {
public:


    string intToRoman(int num) {
        string s;
        map<int, string> convert {
                                 {1, "I"},{4, "IV"},{5, "V"},{9, "IX"},{10, "X"},{40, "XL"},{50, "L"},
                                 {90, "XC"},{100, "C"},{400, "CD"},{500, "D"},{900, "CM"},{1000, "M"}};


        for(auto i = convert.rbegin(); i != convert.rend(); i++){
            while(i->first <= num){
                //cout << num << " = " << " |   s = " << s << endl;
                num -= i->first;
                s+= i->second;
            }
        }
        //cout << "\n"<< s << endl;
        return s;
    }
};


int main( int argc, char** argv)
{
    Solution solver = Solution();
    int value = std::atoi( argv[1] );
    cout << solver.intToRoman( value ) << endl;
    return 0;
}
