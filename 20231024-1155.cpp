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

class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        vl dp(t + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            ll sum = 0;
            for (int j = t; j >= max(0, t - k + 1); --j)
                sum += dp[j];
            sum %= MOD;
            for (int j = t; j >= 0; --j)
            {
                sum -= dp[j];
                if (j - k >= 0)
                    sum += dp[j - k];
                sum += MOD;
                sum %= MOD;
                dp[j] = sum;
            }
        }
        return dp[t];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
