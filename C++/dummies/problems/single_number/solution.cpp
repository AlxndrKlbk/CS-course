#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:

    /**
     * @brief singleNumberXor - impl with XOR usage
     *  TC: O(n), SC: O(1)
     * @param nums - array with nums
     * @return single element in array
     */
    int singleNumberXor(std::vector<int>& nums) {
        int res = 0;
        for (auto const& val : nums) {
            res ^= val;
        }
        return res;
    }

    /**
     * @brief singleNumberXor - impl with sorting
     *  TC: O(n*log(n)), SC: O(1)
     * @param nums - array with nums
     * @return single element in array
     */
    int singleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }

    // also possible impl with unordered_map
};

int main(int argc, char** argv) {
    std::vector<int> vec = {4,1,2,1,2};

    auto solution = Solution();
    auto&& res = solution.singleNumberXor(vec);
    assert(res == 4);

    res = solution.singleNumber(vec);
    assert(res == 4);

    return 0;
}
