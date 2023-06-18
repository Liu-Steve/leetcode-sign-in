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
private:
    int n;
    int m;
    bool dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        if (grid[x][y] == 1 || vis[x][y])
            return true;
        bool ret = !(x == 0 || x == n - 1 || y == 0 || y == m - 1);
        vis[x][y] = true;
        if (x > 0)
            ret = dfs(x - 1, y, grid, vis) && ret;
        if (x < n - 1)
            ret = dfs(x + 1, y, grid, vis) && ret;
        if (y > 0)
            ret = dfs(x, y - 1, grid, vis) && ret;
        if (y < m - 1)
            ret = dfs(x, y + 1, grid, vis) && ret;
        return ret;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0 && vis[i][j] == false)
                    ans += dfs(i, j, grid, vis);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 0}};
    cout << s.closedIsland(v1) << endl;
    return 0;
}
