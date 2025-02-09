#include <string>

#include <cassert>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        auto process = [](int& counter, std::string& source) -> void {
            for(int i=0 ; i < source.size(); i++)
            {
                if(source[i]=='#')
                {
                    counter--;
                    counter = std::max(0,counter);
                }

                else
                {
                    source[counter] = source[i];
                    counter++;
                }
            }
        };

        int k=0;
        int p=0;
        process(k, s);
        process(p, t);

        if(k!=p)
            return false;
        else
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]!=t[i])
                    return false;
            }
            return true;
        }

    }
};

int main() {

    Solution solution;
    auto res = solution.backspaceCompare("ababb###", "a");
    assert(res == false);

    res = solution.backspaceCompare("aabb###", "a");
    assert(res == true);

    return 0;
}
