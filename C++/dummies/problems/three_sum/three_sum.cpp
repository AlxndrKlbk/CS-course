#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>

using std::vector;
using std::set;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    vector<vector<int>> threeSumSet(vector<int>& nums) {
        int target_sum = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> nums_set;
        vector<vector<int>> result;

        for( int i = 0; i < nums.size(); i++ ){
            int j = i + 1;
            int k = nums.size() - 1;

            if(nums[i] > 0)
            {
                break;
            }

            while( j < k )
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target_sum){
                    nums_set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < target_sum){
                    j++;
                } else {
                    k--;
                }
            }

        }

        for( auto triplet: nums_set)
            result.push_back(triplet);

        return result;
    }

    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet = {num[i], num[front], num[back]};
                    res.push_back(triplet);

                    // двигаем левый указатель пока не найдем отличное от текущего числа
                    while (front < back && num[front] == triplet[1]) front++;

                    // двигаем правый указатель пока не найдем отличное от текущего числа
                    while (front < back && num[back] == triplet[2]) back--;
                }

            }

            // ищем отличное от текущего первое число
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;

        }

        return res;

    }

};

int main()
{
    Solution solver;
    vector<int> nums = {0, 2, -1, -1, 25, 9, 0 };
    auto result = solver.threeSum(nums);

    for( auto& nums: result)
    {
        cout << "[";
        for( auto& num: nums)
            cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
