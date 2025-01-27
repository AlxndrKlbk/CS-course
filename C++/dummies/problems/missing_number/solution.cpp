#include <cstdint>
#include <cassert>

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:

    /**
     * @brief missingNumber - regular approach ) O(n*log(n) + n) = O(n*log(n))
     *  n * log(n) -  cause usage of std::sort
     * @param nums - array of numbers
     * @return missing number in array
     */
    int missingNumber(std::vector<int>& nums) {
        uint64_t n = nums.size();
        int cur = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return n;
    }

    /**
     * @brief missingNumberXor - approach based on XOR operator properties
     *  (idea in commutative and destructive XOR propertie (x ^ x = 0))
     * @param nums - array of numbers
     * @return missing number in array
     */
    int missingNumberXor(std::vector<int>& nums) {
        uint64_t n = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];
        }

        for (int i = 0; i <= n ; i++) {
            xor2 ^= i;
        }

        return xor1 ^ xor2;
    }

};

int main()
{
    std::vector<int> arr1 = { 1, 2, 0, 4 };

    Solution solver = Solution();
    auto&& res = solver.missingNumber(arr1);
    assert(res == 3);
    std::cout << "base approach:" << res << std::endl;

    res = solver.missingNumberXor(arr1);
    assert(res == 3);
    std::cout << "XOR approach:" << res << std::endl;

    return 0;
}
