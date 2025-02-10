#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto zeros_it = std::remove(nums.begin(), nums.end(), 0);
        for(;zeros_it != nums.end(); zeros_it++) {
            *zeros_it = 0;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto left = nums.begin();
        while(left != nums.end()) {
            if (*left == 0) {
                for(auto right = left; right != nums.end(); right++) {
                    if (*right != 0) {
                        std::swap(*left, *right);
                        break;
                    }
                }

            }
            left++;
        }
    }
};

class Solution3 {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto first = nums.begin();
        auto last = nums.end();
        first = std::find(first, last, 0);
        if (first != last) {
            for (auto i = first; i != last; i++)
                if (*i != 0 && *first == 0) {
                    std::swap(*first, *i);
                    first++;
                }
        }
    }
};

int main() {
    static const std::vector<int> invariant{1, 1, 3, 0, 0};

    std::vector<int> nums1 {0, 0, 1, 1, 3};
    Solution solution;
    solution.moveZeroes(nums1);
    assert(nums1 == invariant);

    std::vector<int> nums2 {0, 0, 1, 1, 3};
    Solution2 solution2;
    solution2.moveZeroes(nums2);
    assert(nums2 == invariant);

    std::vector<int> nums3 {0, 0, 1, 1, 3};
    Solution3 solution3;
    solution3.moveZeroes(nums3);
    assert(nums3 == invariant);

    return 0;
}
