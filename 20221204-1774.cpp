#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;

class Solution
{
public:
    int closestCost(const vector<int> &base, const vector<int> &top, int V)
    {
        vector<bool> dp(V + 5);
        int ans = 0x3f3f3f3f;
        for (int x : base)
        {
            if (x > V)
                ans = min(ans, x);
            else
                dp[x] = true;
        }
        for (int x : top)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = V; j >= 0; j--)
                {
                    if (dp[j] && j + x > V)
                        ans = min(ans, j + x);
                    if (j > x)
                        dp[j] = dp[j] | dp[j - x];
                }
            }
        }
        for (int i = 0; i <= ans - V && i <= V; i++)
            if (dp[V - i])
                return V - i;
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}