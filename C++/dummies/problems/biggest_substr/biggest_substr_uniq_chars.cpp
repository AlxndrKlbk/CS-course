#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0 , maxlength=0,j=0;
        map<char ,int> mp;
        for(int i=0 ;i<s.size(); i++){
            mp[s[i]]++;
            length++;
            while(mp[s[i]]>1){
                mp[s[j++]]--;
                length--;
            }
            maxlength = max(maxlength,length);
        }
        return maxlength;
    }
};


int main( int argc, char **argv )
{
    string str = argv[1];
    Solution solver = Solution();
    std::cout << solver.lengthOfLongestSubstring( str ) << std::endl;
    return 0;
}
