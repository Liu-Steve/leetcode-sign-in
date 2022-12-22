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
private:
    int gcd(int a, int b)
    {
        while (a && b)
        {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        return a + b;
    }

public:
    int maxScore(vector<int> &nums)
    {
        int n = nums.size();
        int g[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                g[i][j] = gcd(nums[i], nums[j]);
        int dp[1 << n];
        memset(dp, 0, sizeof(dp));
        for (int p = 0; p < (1 << n); ++p)
        {
            int cnt = p;
            cnt = (cnt & 0x5555) + ((cnt >> 1) & 0x5555);
            cnt = (cnt & 0x3333) + ((cnt >> 2) & 0x3333);
            cnt = (cnt & 0x0f0f) + ((cnt >> 4) & 0x0f0f);
            cnt = (cnt & 0x00ff) + ((cnt >> 8) & 0x00ff);
            if (cnt & 1)
                continue;
            for (int i = 0; i < n; ++i)
                if (!((p >> i) & 1))
                    for (int j = i + 1; j < n; ++j)
                        if (!((p >> j) & 1))
                        {
                            int pn = p | (1 << i) | (1 << j);
                            dp[pn] = max(dp[pn], dp[p] + ((cnt >> 1) + 1) * g[i][j]);
                        }
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
    io;
    Solution s;
    vi v1 = {1, 2};
    cout << s.maxScore(v1) << endl;
    vi v2 = {3, 4, 6, 8};
    cout << s.maxScore(v2) << endl;
    vi v3 = {1, 2, 3, 4, 5, 6};
    cout << s.maxScore(v3) << endl;
    return 0;
}