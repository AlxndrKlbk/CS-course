#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid_pos = total / 2;
        int mid_pos_second = total % 2 != 0 ? mid_pos: mid_pos + 1;

        vector<int>::const_iterator iter_nums1 = nums1.begin(), iter_nums2 = nums2.begin();

        int iter = 0, current = 0, prev = 0;
        while( true )
        {
            prev = current;
            if( iter_nums1 == nums1.end() && iter_nums2 != nums2.end())
            {
                current = *iter_nums2;
                ++iter_nums2;
            }
            else if( iter_nums2 == nums2.end() && iter_nums1 != nums1.end())
            {
                current = *iter_nums1;
                ++iter_nums1;
            }
            else if( *iter_nums1 > *iter_nums2 )
            {
                current = *iter_nums2;
                ++iter_nums2;
            }
            else
            {
                current = *iter_nums1;
                ++iter_nums1;
            }

            if( (mid_pos != mid_pos_second && iter == mid_pos_second - 1) ||
                (mid_pos == mid_pos_second && iter == mid_pos_second) )
                break;
            iter++;
        }
        if( total % 2 != 0 )
            return current;
        return ( static_cast<double>(prev) + current) / 2;
    }
};

int main()
{
    vector<int> arr1 = { 1, 2 };
    vector<int> arr2 = { 3, 4 };

    Solution solver = Solution();
    std::cout << solver.findMedianSortedArrays(arr1, arr2) << std::endl;
    return 0;
}
