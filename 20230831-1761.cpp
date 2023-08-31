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
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<vector<bool>> g(n, vector<bool>(n));
        vector<int> deg(n);
        for (auto &e : edges)
        {
            g[e[0] - 1][e[1] - 1] = g[e[1] - 1][e[0] - 1] = true;
            deg[e[0] - 1]++;
            deg[e[1] - 1]++;
        }
        int ans = INT32_MAX;
        for (int i = 0; i < n - 2; ++i)
            for (int j = i + 1; j < n - 1; ++j)
            {
                if (!g[i][j])
                    continue;
                for (int k = j + 1; k < n; ++k)
                    if (g[i][k] && g[j][k])
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
            }
        return ans != INT32_MAX ? ans : -1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
