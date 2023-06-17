#include <vector>
#include <numeric>
#include <utility>
#include <queue>
#include <iostream>

using std::vector, std::pair, std::priority_queue;
using std::accumulate, std::greater, std::make_pair;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<int> result;
        vector<pair<int,int>> rows(mat.size());

        for (int i = 0; i < mat.size(); i++)
        {
            rows[i] = make_pair(accumulate(mat[i].begin(), mat[i].end(), 0), i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(rows.begin(), rows.end());

        while (!pq.empty() && k > 0) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};

int main()
{
    vector< vector< int > > task = { {1, 1, 0 }, {1, 0, 0} };
    Solution solver = Solution();
    auto vec = solver.kWeakestRows( task, 4 );
    for( auto& val: vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
