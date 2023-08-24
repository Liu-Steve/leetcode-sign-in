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
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> r(n);
        vector<int> c(m);
        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j])
                {
                    r[i]++;
                    c[j]++;
                    p.emplace_back(i, j);
                }
        int ans = 0;
        for (auto [x, y] : p)
            if (r[x] != 1 || c[y] != 1)
                ans++;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
