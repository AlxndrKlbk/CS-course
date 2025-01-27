#include <vector>

#include <cassert>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> res;
        int pos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                pos = nums[i] * -1 - 1;
            } else {
                pos = nums[i] - 1;
            }

            if (nums[pos] > 0) {
                nums[pos] = -nums[pos];
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.emplace_back(i+1);
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vec = {1, 2, 5, 6, 6, 6};

    auto solution = Solution();
    auto const& res = solution.findDisappearedNumbers(vec);
    assert((res == std::vector<int>{3, 4}));
    return 0;
}
