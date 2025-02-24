#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <chrono>

#include <memory.h>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using timer = std::chrono::high_resolution_clock;

class Solution {
public:
    int dp[21][3002]; // dp array with offset for -1000 to +1000 range
    const int OFFSET = 1000; // Offset to handle negative target values

    // Recursive function to solve the problem
    int solve(int ind, vector<int>& nums, int target) {
        // Base cases
        if (ind >= nums.size()) {
            return target == 0 ? 1 : 0;
        }

        // Check if already computed
        if (dp[ind][target + OFFSET] != -1) {
            return dp[ind][target + OFFSET];
        }

        // Recursively calculate the number of ways
        int ans = 0;
        ans += solve(ind + 1, nums, target - nums[ind]); // Subtract current number
        ans += solve(ind + 1, nums, target + nums[ind]); // Add current number

        return dp[ind][target + OFFSET] = ans; // Store result in dp array
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, nums, target); // Start recursion from index 0
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return cal(nums, target, 0, 0);
    }

    int cal(vector<int>& nums, int tar, int idx, int currSum) {
        if (idx == nums.size()) {
            return (currSum == tar) ? 1 : 0;
        }

        int add = cal(nums, tar, idx + 1, currSum + nums[idx]);
        int sub = cal(nums, tar, idx + 1, currSum - nums[idx]);

        return add + sub;
    }
};
int main( int argc, char* argv[]) {
    std::vector<int> nums {3, 33, 47, 61, 107, 1, 1, 2};
    int target = 249;
    Solution solver;

    auto&& start = timer::now();
    auto result = solver.findTargetSumWays(nums, target);
    auto&& stop = timer::now();
    assert(result == 3);
    std::cout << "Memoryzation recursion runtime:" << stop - start << std::endl;

    Solution2 solver2;
    start = timer::now();
    result = solver2.findTargetSumWays(nums, target);
    stop = timer::now();
    assert(result == 3);
    std::cout << "Recursion runtime:" << stop - start << std::endl;

    return 0;
}
