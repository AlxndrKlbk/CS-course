#include <vector>
#include <chrono>

#include <iostream>
#include <cassert>

using timer = std::chrono::high_resolution_clock;

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0;
        }

        double max = std::numeric_limits<double>::lowest();

        int pos = 0;
        int max_index = nums.size() - k;

        double&& cur = 0;
        for (int i = 0; i < k; i++) {
            cur += nums[pos + i];
        }
        if (cur > max) {
            max = cur;
        }
        pos++;

        while(pos <= max_index) {
            cur -= nums[pos - 1];
            cur += nums[pos + k - 1];
            if (cur > max) {
                max = cur;
            }
            pos++;
        }
        return max/(double)k;
    }
};

void test(Solution& solution)
{
    std::vector<int> nums {-1};
    auto&& start = timer::now();
    auto&& res = solution.findMaxAverage(nums, 1);
    auto&& stop = timer::now();
    std::cout << "sliding window implementation runtime:" << stop - start << std::endl;

    assert(res == -1.0);
}

int main (int argc, char** argv)
{
    Solution solution;
    test(solution);
    return 0;
}
