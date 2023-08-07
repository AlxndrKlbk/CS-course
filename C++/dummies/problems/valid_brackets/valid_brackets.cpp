#include <stack>
#include <string>
#include <unordered_map>
#include <iostream>

using std::stack;
using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        unordered_map<char,char> char_map = {
            {']','['},
            {')','('},
            {'}','{'}
        };

        for(char ch:s){
            if (ch == '(' || ch== '[' || ch =='{')
                char_stack.push(ch);
            else
            {
                if (char_stack.empty() || char_stack.top() != char_map[ch])
                    return false;
                char_stack.pop();
            }
        }
        return char_stack.empty();
    }
};


int main(int argc, char* argv[])
{
    string str = argv[1];
    Solution solver;
    cout << solver.isValid(str) << endl;
    return 0;
}
