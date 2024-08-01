#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        while(!strs.empty())
        {
            vector<string> group = {strs[0]};
            strs.erase(strs.begin());

            unordered_map<char, int> charMap;

            for(auto character : group[0]){
                charMap[character]++;
            }

            strs.erase(
                std::remove_if(strs.begin(),
                               strs.end(),
                               [&group, &charMap](const string& item) {
                                   if (group[0].size() != item.size()) return false;

                                   unordered_map<char, int> curMap;
                                   for(auto character : item) {
                                       curMap[character]++;
                                   }

                                   for(auto character: item) {
                                       if (curMap[character] != charMap[character]) return false;
                                   }
                                   group.emplace_back(item);
                                   return true;
                               }), strs.end());
            result.emplace_back(group);
        }
        return result;
    }
};


int main(int argc, char** argv)
{
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    auto const& groups = Solution::groupAnagrams(strs);
    for(auto const& vec : groups) {
        std::cout << "[";
        for (auto const& str : vec) {
            std::cout << str << " ; ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
