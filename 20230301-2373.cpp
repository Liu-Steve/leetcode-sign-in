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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size() - 2;
        int dir[10] = {0, 1, 1, 0, 2, 1, 2, 2, 0, 0};
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < 9; ++i)
        {
            int dx = dir[i];
            int dy = dir[i + 1];
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < n; ++y)
                    ans[x][y] = max(ans[x][y], grid[x + dx][y + dy]);
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