#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    void solve(int n , int start , int close, string temp ,vector<string>&result)
    {
        if(temp.size()==n*2)
        {
            result.push_back(temp);
            return ;
        }
        if(start < n)
        {
            solve(n,start + 1, close,temp + "(", result);
        }
        if(close < start )
        {
            solve(n,start, close + 1,temp + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(n,0, 0,"", result);
        return result;
    }
};


int main( int argc, char* argv[]) {
    int parenthesis_count = atoi(argv[1]);
    Solution solver;
    auto result = solver.generateParenthesis(parenthesis_count);
    for (auto& str: result) {
        cout << str << endl;
    }
    return 0;
}
