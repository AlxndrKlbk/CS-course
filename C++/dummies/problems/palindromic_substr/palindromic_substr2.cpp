#include <utility>
#include <vector>
#include <string>
#include <iostream>

using std::string, std::vector, std::pair;
typedef pair<int, int> index_type;


class Solution {
public:
    string longestPalindrome(string s) {

        int max_length = s.length();
        vector< index_type > indexes;
        index_type result = index_type(0, 0);
        for( int i = 0; i < max_length; i++)
        {
            if(i + 1 < max_length && s[i] == s[ i + 1 ])
                indexes.push_back( index_type( i, i + 1 ));
            if(i + 2 < max_length && s[i] == s[ i + 2 ])
                indexes.push_back( index_type( i, i + 2 ));
        }
        int max_poly = 0;
        bool changed;
        while( indexes.size() > 0 )
        {
            int cur_index = 0;
            for( auto index = indexes.begin(); index != indexes.end();)
            {
                if( index->first - 1 >= 0 && index->second + 1 < max_length )
                {
                    if( s[ index->first - 1 ] == s[index->second + 1 ] )
                    {
                        index->first--;
                        index->second++;
                    }
                    else
                    {
                        if ( result.second - result.first < index->second - index->first )
                            result = *index;
                        index = indexes.erase(index);
                        continue;
                    }
                }
                else
                {
                    if ( result.second - result.first < index->second - index->first )
                        result = *index;
                    index = indexes.erase(index);
                    continue;
                }

                ++index;
            }
        }

        if( result.second != 0 )
            return s.substr( result.first , result.second - result.first + 1);
        return s.substr(0, 1);
    }
};

int main()
{
    Solution solver = Solution();
    string str = "abadd";
    std::cout << solver.longestPalindrome( str ) << std::endl;
    return 0;
}
