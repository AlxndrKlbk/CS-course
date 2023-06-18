#include <vector>

using std::vector;

class Solution {
private:
    int lower_bound( vector< int >& nums, int low, int high, int target ){
        while( low <= high ){
            int mid = ( low + high ) >> 1;
            if( nums[mid] < target ){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector< int > searchRange( vector< int >& nums, int target ) {
        int low = 0, high = nums.size()-1;
        int startingPosition = lower_bound( nums, low, high, target );
        int endingPosition = lower_bound( nums, low, high, target + 1 ) - 1;
        if( startingPosition < nums.size() && nums[ startingPosition ] == target ){
            return { startingPosition, endingPosition };
        }
        return { -1, -1 };
    }
};

int main()
{
    Solution solver = Solution();
    vector< int > list = { 5,8,8,8,8,10 };
    solver.searchRange( list, 8 );
    return 0;
}
