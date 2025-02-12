#include <vector>

#include <cassert>

class Solution {
public:

    // Donuld Knutt solve it for one day
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


int main (int argc, char** argv)
{
    std::vector<int> nums{1, 2, 4, 4, 3};
    Solution solution;
    auto const& res = solution.findDuplicate(nums);
    assert(res == 4);

    return 0;
}
