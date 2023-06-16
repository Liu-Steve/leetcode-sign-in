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
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
        vector<int> pre(n, 0);
        for (auto &r : relations)
            pre[r[1] - 1] |= 1 << (r[0] - 1);
        vector<int> dp(1 << n, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i)
        {
            int ch = 0;
            for (int j = 0; j < n; ++j)
                if ((i & (1 << j)) && (pre[j] & i) == 0)
                    ch |= 1 << j;
            if (__builtin_popcount(ch) <= k)
            {
                dp[i] = min(dp[i], dp[i ^ ch] + 1);
                continue;
            }
            for (int j = ch; j; j = (j - 1) & ch)
                if (__builtin_popcount(j) == k)
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{2, 1}, {3, 1}, {1, 4}};
    cout << s.minNumberOfSemesters(4, v1, 2) << endl;
    return 0;
}
