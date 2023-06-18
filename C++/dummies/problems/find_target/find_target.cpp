#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        vector<int> result;
        bool founded = false;
        sort(nums.begin(), nums.end() );

        for( int i = 0; i < nums.size(); i++)
        {
            if( nums[i] == target)
            {
                founded = true;
                result.push_back( i );
            }
            else if( founded )
            {
                break;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        bool founded = false;
        sort(nums.begin(), nums.end() );

        for( int i = 0; i < nums.size(); i++)
        {
            if( nums[i] == target && !founded)
            {
                founded = true;
                result.push_back( i );
            }
            else if( nums[i] != target  && founded )
            {
                result.push_back( i - 1 );
                break;
            }
        }
        if( 1 < result.size( ) && result.size( ) < 2 )
            result.push_back( result[ 0 ] );
        else if ( result.empty() )
        {
            result.push_back( -1 );
            result.push_back( -1 );
        }

        return result;
    }
};

int main()
{
    Solution solver = Solution();
    vector< int > list = { 5,7,7,8,8,10 };
    solver.targetIndices( list, 8 );
    solver.searchRange( list, 8 );
    return 0;
}
