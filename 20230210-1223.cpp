#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int dieSimulator(int n, vi &rollMax)
    {
        int dp[n + 1][7];
        for (int i = 0; i < 6; ++i)
            dp[0][i] = 0;
        dp[0][6] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                int temp = i - 1 - rollMax[j];
                int sub = temp < 0 ? 0 : dp[temp][6] - dp[temp][j];
                dp[i][j] = (dp[i - 1][6] - sub) % MOD;
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
            dp[i][6] = 0;
            for (int j = 0; j < 6; ++j)
                dp[i][6] = (dp[i][6] + dp[i][j]) % MOD;
        }
        return dp[n][6];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 1, 2, 2, 2, 3};
    cout << s.dieSimulator(2, v1) << endl;
    return 0;
}