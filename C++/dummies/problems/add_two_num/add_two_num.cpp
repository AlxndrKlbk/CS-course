#include <vector>
#include <unordered_map>
#include <algorithm>>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector< int > result;

        for( int i = 0; i < nums.size(); i++ )
        {
            for( int j = i + 1; j < nums.size(); j++ )
            {
                if( nums[i] + nums[j] == target )
                {
                    result.push_back( i );
                    result.push_back( j );
                    return result;
                }

            }
        }
        return result;
    }

    vector<int> twoSumMap(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {};
    }

    vector<int> twoSumBinSearch(vector<int>& numbers, int target) {
        std::sort(numbers.begin(), numbers.end());
        vector<int> ans;
        int l=0,r=numbers.size()-1;
        while(l<=r)
        {
            int temp=numbers[l] + numbers[r];
            if(temp==target)
            {
                ans.push_back(l);
                ans.push_back(r);
                break;
            }
            else if(temp>target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return ans;
    }

};

int main()
{
    Solution solver = Solution();
    vector< int > nums = { 2, 3, 10 , 23, 1, 5, 8, 9, 7 };
    auto res1 = solver.twoSum( nums, 10 );
    auto res2 = solver.twoSumMap( nums, 10 );
    auto res3 = solver.twoSumBinSearch( nums, 10);

    return 0;
}
