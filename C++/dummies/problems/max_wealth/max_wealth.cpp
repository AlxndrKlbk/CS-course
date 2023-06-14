#include <vector>

using std::vector;

class Solution {
public:
    int maximumWealth( vector < vector <int>>& accounts) {

        int max_wealth = 0;
        int accum = 0;

        for( auto& customer_i: accounts)
        {
            for( auto& wealth_j: customer_i)
                accum += wealth_j;

            if( accum > max_wealth )
                max_wealth = accum;
            accum = 0;
        }

        return max_wealth;
    }
};

int main()
{
    Solution solver = Solution();
    vector< vector < int> > input = { { 1, 2, 3 }, { 3, 2, 3 } } ;
    auto max_wealth = solver.maximumWealth( input );
    return max_wealth;
}
