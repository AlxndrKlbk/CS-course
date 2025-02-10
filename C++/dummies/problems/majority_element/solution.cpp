#include <vector>
#include <algorithm>
#include <unordered_map>

#include <cassert>

// O(n) time and O(1) space
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

// O(nlog(n)) time and O(1) space
class Solution2 {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

// O(n) time and O(n) space
class Solution3 {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for(auto x: m){
            if(x.second > n){
                return x.first;
            }
        }
        return 0;
    }
};

int main() {
    std::vector<int> nums {0, 0, 1, 1, 3, 2, 3, 3, 4, 3, 3};
    Solution solution;
    auto res = solution.majorityElement(nums);
    assert(res == 3);

    Solution2 solution2;
    res = solution2.majorityElement(nums);
    assert(res == 3);

    Solution3 solution3;
    res = solution3.majorityElement(nums);
    assert(res == 3);

    return 0;
}
