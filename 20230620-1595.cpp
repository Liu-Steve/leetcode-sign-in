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
    int connectTwoGroups(vector<vector<int>> &cost)
    {
        int n = cost.size();
        int m = cost[0].size();
        vector<int> minCost(m, INT32_MAX);
        for (auto &v : cost)
            for (int i = 0; i < m; ++i)
                minCost[i] = min(minCost[i], v[i]);
        vector<int> dp(1 << m, 0);
        for (int i = 0; i < (1 << m); ++i)
            for (int j = 0; j < m; ++j)
                if ((1 << j) & i)
                    dp[i] += minCost[j];
        for (int i = 0; i < n; ++i)
            for (int j = (1 << m) - 1; j >= 0; --j)
            {
                int res = INT32_MAX;
                for (int k = 0; k < m; ++k)
                    res = min(res, dp[j & ~(1 << k)] + cost[i][k]);
                dp[j] = res;
            }
        return dp[(1 << m) - 1];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
