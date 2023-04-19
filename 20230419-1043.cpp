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
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            int mx = 0;
            for (int j = i; j >= 1 && i - j < k; --j)
            {
                mx = max(mx, arr[j - 1]);
                dp[i] = max(dp[i], dp[j - 1] + mx * (i - j + 1));
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