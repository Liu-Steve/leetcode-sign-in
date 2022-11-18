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

class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {
        const int INF = INT32_MAX;
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            dp[i] = INF;
            for (int c : coins) 
            {
                if (i - c >= 0 && dp[i - c] != INF)
                {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main() {
    io;
    Solution s;
    vi v = {1};
    cout << s.coinChange(v, 0) << endl;
    return 0;
}