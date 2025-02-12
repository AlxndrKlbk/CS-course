#include <vector>
#include <math.h>

#include <cassert>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> ans;
        int n = size(nums);
        for(int i=0; i < n; i++){
            int x = abs(nums[i]);
            if (nums[x-1] < 0)
            {
                ans.push_back(x);
            }
            nums[x-1] *= -1;
        }
        return ans;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums{1, 2, 2, 5, 5, 6, 1};
    std::vector<int> invarinat{2, 5, 1};
    Solution solution;
    auto const& res = solution.findDuplicates(nums);
    assert(res == invarinat);

    return 0;
}
