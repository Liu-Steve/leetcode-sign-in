#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp1(grid[m - 1]), dp2(n);
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp2[j] = INT32_MAX;
                for (int k = 0; k < n; ++k)
                {
                    int ele = grid[i][j];
                    dp2[j] = min(dp2[j], ele + moveCost[ele][k] + dp1[k]);
                }
            }
            swap(dp1, dp2);
        }
        return *min_element(dp1.begin(), dp1.end());
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
