#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <cassert>

// main_ituls lib
#include "main_func_utils.hpp"

namespace {

using std::vector;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};

constexpr int TARGET_VALUE_INDEX = 1;
constexpr int VALUES_START_INDEX = 2;

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<std::pair<int, int>> sortedNums(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(),sortedNums.end());
        while (l < r) {
            int temp = sortedNums[l].first + sortedNums[r].first;
            if (temp == target) {
                return {sortedNums[l].second, sortedNums[r].second};
            } else if (temp < target) {
                l++;
            } else {
                r--;
            }
        }
        return {-1,-1};
    }
};

}

int main(int argc, char** argv)
{
    vector<int> buff;
    comand_line_args_to_vector(VALUES_START_INDEX, argc, buff, argv);

    auto const& resp = Solution::twoSum(buff, atoi(argv[TARGET_VALUE_INDEX]));
    for (auto const& val : resp) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    buff = {3, 2, 4};

    Solution2 solution2;
    auto&& res = solution2.twoSum(buff, 6);
    assert(res[0] == 1 && res[1] == 2);

    Solution3 solution3;
    res = solution3.twoSum(buff, 6);
    assert(res[0] == 1 && res[1] == 2);

    return 0;
}
