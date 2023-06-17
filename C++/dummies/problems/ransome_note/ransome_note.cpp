#include <string>
#include <iostream>

using std::string;
using std::cout, std::cin;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if( ransomNote.size() > magazine.size() )
        {
            return false;
        }

        int first_index = 97;
        int storage[ 26 ] = { 0 };
        int index;

        for( auto& letter : magazine )
        {
            storage[ (int)letter - first_index ] ++;
        }

        for( auto& letter : ransomNote )
        {
            index = (int)letter - first_index;
            if( storage[ index ] == 0 )
            {
                return false;
            }
            storage[ index ] --;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution solver = Solution();
    cout << solver.canConstruct( "abba", "bobba") << std::endl;
    return 0;
}

