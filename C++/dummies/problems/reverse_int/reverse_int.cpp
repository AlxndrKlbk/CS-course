#include "limits.h"
#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while(x){
            if (result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;
            result = result * 10 + x % 10;
            x = x / 10;
        }

        return result;
    }

    int reverse_with_long(int x) {
        long result = 0;
        while(x){
            result = result * 10 + x % 10;
            x = x / 10;
        }

        if(result > INT_MAX || result < INT_MIN)
            return 0;
        return int(result);
    }
};

int main(int argc, char* argv[])
{
    int value = atoi(argv[1]);
    Solution solver;
    solver.reverse(value);
    cout << solver.reverse(value) << endl;
    return 0;
}
