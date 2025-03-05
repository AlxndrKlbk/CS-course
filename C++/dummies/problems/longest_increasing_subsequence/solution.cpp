#include <vector>
#include <algorithm>

#include <cassert>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> res;

        for (int n : nums) {
            if (res.empty() || res.back() < n) {
                res.push_back(n);
            } else {
                int idx = binarySearch(res, n);
                res[idx] = n;
            }
        }

        return res.size();
    }

private:
    int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main (int argc, char** argv)
{
    std::vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    Solution solution;
    auto res = solution.lengthOfLIS(nums);
    assert(res == 4);

    return 0;
}
