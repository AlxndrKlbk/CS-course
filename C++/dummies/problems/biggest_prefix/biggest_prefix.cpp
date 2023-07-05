#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, smallest = 100;
        string substr, i_str;
        for( auto& str: strs )
        {
            int str_size = str.size();
            if( str_size < smallest )
                smallest = str_size;
        }

        bool exit = false;
        while( i < smallest)
        {
            substr = strs[0][i];
            for(auto& str: strs)
            {
                i_str = str[i];
                if( i_str != substr )
                {
                    exit = true;
                    break;
                }
            }

            if(exit)
                break;
            i++;
        }

        if(i == 0)
            return "";
        else
        {
            substr = "";
            int z;
            for(z = 0; z < i; z++ )
            {
                substr.push_back(strs[0][z]);
            }
            return substr;
        }
    }
};

int main( int argc, char **argv)
{
    Solution solver;
    vector< string > task = { "bem", "bemost" };
    std::cout << solver.longestCommonPrefix( task ) << std::endl;
    return 0;
}
