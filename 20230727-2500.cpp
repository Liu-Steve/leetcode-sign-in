#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
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
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        for (auto &line : grid)
            sort(line.begin(), line.end());
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            int val = 0;
            for (int j = 0; j < m; ++j)
                val = max(val, grid[j][i]);
            ans += val;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
