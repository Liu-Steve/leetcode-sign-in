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
    int b[9] = {1, 2, -1, -2, 1, -2, -1, 2, 1};
    bool check(vector<vector<int>> &grid, int x, int y)
    {
        if (grid[x][y] == 0)
            return x == 0 && y == 0;
        int n = grid.size();
        for (int i = 0; i < 8; ++i)
        {
            int p = x + b[i];
            int q = y + b[i + 1];
            if (p < 0 || p >= n || q < 0 || q >= n)
                continue;
            if (grid[p][q] == grid[x][y] - 1)
                return true;
        }
        return false;
    }

public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (!check(grid, i, j))
                    return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
