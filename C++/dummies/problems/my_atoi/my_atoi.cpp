#include <string>
#include "limits.h"

using std::string;


class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        char c;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        //either '+', '-' or digit, otherwise return 0
        int sgn = 1;
        long long x = 0;
        int digit_len = 0;
        c = s[i];
        if (c == '-')
            sgn = -1;
        else if (c == '+')
            sgn = 1;
        else if (!isdigit(c))
            return 0;
        else {//isdigit
            x = c - '0';
            if (x > 0)
                digit_len++;
        }
        i++;

        //major loop. For dealing with overflow, use digit_len
        //to track the actual length of x
        while(i < n && digit_len <= 11){
            c = s[i];
            if (!isdigit(c))
                break;
            x = 10 * x + ( c - '0');
            i++;
            if (x > 0)
                digit_len++;
        }
        x = sgn * x;

        //Everything is OK!
        if (x > INT_MAX) x = INT_MAX;
        else if (x < INT_MIN)  x = INT_MIN;
        return x;
    }
};


int main(){
    Solution solution;
    return solution.myAtoi("  107");
}
