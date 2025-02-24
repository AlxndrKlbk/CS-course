#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    void solve(int max , int open , int close, string temp ,vector<string>&result)
    {
        if (temp.size() == max * 2)
        {
            result.push_back(temp);
            return ;
        }
        if (open < max)
        {
            solve(max,open + 1, close,temp + "(", result);
        }
        if (close < open )
        {
            solve(max,open, close + 1,temp + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(n,0, 0,"", result);
        return result;
    }

};

auto cout_parentheses = [](std::vector<std::string> const& res) -> void {
    for (auto& str: res) {
        cout << str << endl;
    }
};

int main( int argc, char* argv[]) {
    int parenthesis_count = atoi(argv[1]);
    Solution solver;
    auto result = solver.generateParenthesis(parenthesis_count);
    cout_parentheses(result);

    return 0;
}
