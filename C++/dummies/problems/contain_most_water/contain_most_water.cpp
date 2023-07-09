#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size - 1;
        int result = 0, i_left = 0, i_right = 0;
        int sum = 0, cand_sum = 0, distance = 0;
        while( left < right)
        {
            distance = right - left;
            i_left = height[left];
            i_right = height[right];
            cand_sum = i_left < i_right? i_left * distance: i_right * distance;

            sum = sum < cand_sum ? cand_sum: sum;
            if( i_left < i_right )
                left++;
            else
                right--;
        }

        return sum;
    }
};


int main(int argc, char** argv)
{
    Solution solver = Solution();
    vector<int> box = { 1, 2, 8, 2, 4, 5, 6, 7, 3 };
    std::cout << solver.maxArea( box ) << std::endl;
    return 0;
}

