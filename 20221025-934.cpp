#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef pair<int, int> p;

class Solution {
private:
    queue<p> v1;
    int n;

    bool dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == -1)
            return false;
        if (!grid[x][y])
            return true;
        grid[x][y] = -1;
        bool edge = false;
        edge |= dfs(grid, x + 1, y);
        edge |= dfs(grid, x - 1, y);
        edge |= dfs(grid, x, y + 1);
        edge |= dfs(grid, x, y - 1);
        if (edge)
            v1.emplace(x, y);
        return false;
    }

    void addVisit(vector<vector<int>>& grid)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    return;
                }
    }

    bool sign(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == -1)
            return false;
        if (grid[x][y])
            return true;
        grid[x][y] = -1;
        v1.emplace(x, y);
        return false;
    }

    bool neighbor(vector<vector<int>>& grid, int x, int y)
    {
        bool ret = false;
        ret |= sign(grid, x + 1, y);
        ret |= sign(grid, x - 1, y);
        ret |= sign(grid, x, y + 1);
        ret |= sign(grid, x, y - 1);
        return ret;
    }

public:
    int shortestBridge(vector<vector<int>>& grid)
    {
        n = grid.size();
        int ret = 0;
        addVisit(grid);
        while (true) {
            int sz = v1.size();
            while (sz--) {
                p pos = v1.front();
                v1.pop();
                if (neighbor(grid, pos.first, pos.second))
                    return ret;
            }
            ret++;
        }
        return -1;
    }
};

int main()
{
    io;
    Solution s;
    vector<vector<int>> grid = { { 0, 1, 0, 0, 0 }, { 0, 1, 0, 1, 1 }, { 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
    cout << s.shortestBridge(grid) << endl;
    return 0;
}