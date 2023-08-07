#include <string>
#include <vector>
#include <iostream>
#include "stdlib.h"


using std::string;
using std::vector;
using std::cout;
using std::endl;


class Solution {
public:

    string convert(string s, int numRows) {

        if(numRows <= 1)
            return s;

        vector<string>v(numRows, "");

        int j = 0, dir = -1;

        for(int i = 0; i < s.length(); i++)
        {

            if(j == numRows - 1 || j == 0)
                dir *= (-1);

            v[j] += s[i];
            if(dir == 1)
                j++;
            else
                j--;
        }

        string res;

        for(auto &it : v) res += it;

        return res;

    }
};

int main(int argc, char* argv[]) {
    string str = argv[1];
    int rows  = atoi(argv[2]);
    Solution solver;

    cout << solver.convert(str, rows) << endl;
    return 0;
}
