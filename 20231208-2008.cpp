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
    ll maxTaxiEarnings(int n, vv &rides)
    {
        sort(rides.begin(), rides.end(), [&](vi &r1, vi &r2)
             { return r1[1] < r2[1]; });
        vl dp(n + 1, 0);
        int p = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            while (p < rides.size() && rides[p][1] == i)
            {
                dp[i] = max(dp[i], dp[rides[p][0]] - rides[p][0] + rides[p][1] + rides[p][2]);
                p++;
            }
        }
        return dp[n];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
