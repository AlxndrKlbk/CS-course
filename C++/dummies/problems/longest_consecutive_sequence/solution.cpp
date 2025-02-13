#include <vector>
#include <unordered_set>

#include <cassert>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = std::max(longest, length);
            }
        }

        return longest;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    Solution solution;
    auto res = solution.longestConsecutive(nums);
    assert(res == 9);

    return 0;
}
