#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int countNegatives( vector< vector < int > >& grid) {
        int i, j;
        int row = grid.size();
        int col = grid[0].size();
        int negative_count = 0;

        for( i = 0; i < row; i++)
        {
            for( j = 0; j < col; j++ )
            {
                if( grid[i][j] < 0 )
                    break;
                negative_count ++;
            }
        }
        return row * col - negative_count;
    }
};

int main()
{
    Solution solver = Solution();
    vector< vector< int > > grid = { { 1, 2, 3 }, {2, 3, -1} };
    std::cout << solver.countNegatives( grid ) << std::endl;
    return 0;
}
