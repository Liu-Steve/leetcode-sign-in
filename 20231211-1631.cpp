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
private:
    int n;
    int m;
    const int b[5] = {-1, 0, 1, 0, -1};
    bool dfs(int cost, int x, int y, int lh, vv &heights, vv &vis)
    {
        if (x < 0 || x >= n || y < 0 || y >= m ||
            vis[x][y] || abs(heights[x][y] - lh) > cost)
            return false;
        if (x == n - 1 && y == m - 1)
            return true;
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + b[i];
            int ny = y + b[i + 1];
            if (dfs(cost, nx, ny, heights[x][y], heights, vis))
                return true;
        }
        return false;
    }

public:
    int minimumEffortPath(vv &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vv vis(n, vi(m, 0));
        int l = -1;
        int r = 1000001;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            vv nvis(vis);
            if (dfs(mid, 0, 0, heights[0][0], heights, nvis))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
