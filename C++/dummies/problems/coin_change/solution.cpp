#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    minCoins[i] = std::min(minCoins[i], 1 + minCoins[i - coins[j]]);
                }
            }
        }

        return minCoins[amount] != amount + 1 ? minCoins[amount] : -1;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {186, 419, 83, 408};
    int amount = 6249;
    Solution solution;
    auto res = solution.coinChange(nums, amount);
    assert(res == 20);

    nums = {1, 2, 5};
    amount = 11;
    res = solution.coinChange(nums, amount);
    assert(res ==  3);
    return 0;
}
