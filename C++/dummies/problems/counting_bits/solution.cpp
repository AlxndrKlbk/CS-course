#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution solver = Solution();
    auto const& res = solver.countBits(6);
    for (auto const& val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}

