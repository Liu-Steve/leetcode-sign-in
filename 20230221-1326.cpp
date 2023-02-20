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
typedef pair<double, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int minTaps(int n, vector<int> &r)
    {
        const int inf = INT32_MAX;
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= r[0]; i++)
            dp[i] = 1;
        for (int i = r[0] + 1; i <= n; i++)
            dp[i] = inf;
        for (int i = 1; i <= n; i++)
        {
            int edge = max(0, i - r[i]);
            if (dp[edge] == inf)
                continue;
            for (int j = edge + 1; j <= i + r[i] && j <= n; j++)
                dp[j] = min(dp[j], dp[edge] + 1);
        }
        return dp[n] == inf ? -1 : dp[n];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {3, 4, 1, 1, 0, 0};
    cout << s.minTaps(5, v1) << endl;
    vi v2 = {0, 0, 0, 0};
    cout << s.minTaps(3, v2) << endl;
    vi v3 = {3, 4, 1, 1, 0, 0, 0, 2, 1};
    cout << s.minTaps(8, v3) << endl;
    return 0;
}