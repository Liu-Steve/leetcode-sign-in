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
    const int b[5] = {1, 0, -1, 0, 1};
    int n;
    int m;
    int len;
    int dfs(vector<vector<int>> &grid, int x, int y, int cnt)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1)
            return 0;
        if (grid[x][y] == 2)
            return cnt == len;
        int ans = 0;
        grid[x][y] = -1;
        for (int i = 0; i < 4; ++i)
            ans += dfs(grid, x + b[i], y + b[i + 1], cnt + 1);
        grid[x][y] = 0;
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        len = 0;
        int x = -1;
        int y = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] != -1)
                    len++;
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        return dfs(grid, x, y, 1);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
