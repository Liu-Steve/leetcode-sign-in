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
    bool possibleToStamp(vv &grid, int h, int w)
    {
        int n = grid.size();
        int m = grid[0].size();
        vv sgrid(n + 1, vi(m + 1, 0));
        vv scnt(n + 1, vi(m + 1, 0));
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                sgrid[x + 1][y + 1] = sgrid[x][y + 1] + grid[x][y];
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                sgrid[x + 1][y + 1] += sgrid[x + 1][y];
        for (int x = h; x <= n; ++x)
            for (int y = w; y <= m; ++y)
                if (!grid[x - 1][y - 1] && sgrid[x][y] - sgrid[x - h][y] - sgrid[x][y - w] + sgrid[x - h][y - w] == 0)
                {
                    scnt[x][y] += 1;
                    scnt[x - h][y - w] += 1;
                    scnt[x - h][y] -= 1;
                    scnt[x][y - w] -= 1;
                }
        for (int x = 1; x <= n; ++x)
            for (int y = 0; y <= m; ++y)
                scnt[x][y] += scnt[x - 1][y];
        for (int x = 0; x <= n; ++x)
            for (int y = 1; y <= m; ++y)
                scnt[x][y] += scnt[x][y - 1];
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                if (!grid[x][y] && !scnt[x][y])
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
