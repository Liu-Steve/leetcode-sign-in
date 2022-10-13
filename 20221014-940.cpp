#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution
{
public:
    int distinctSubseqII(string &s)
    {
        int last[26];
        for (int i = 0; i < 26; ++i)
            last[i] = -1;
        int len = s.size();
        long long dp = 0;
        const long long MOD = 1000000007;
        for (int i = 0; i < len; ++i)
        {
            int idx = s[i] - 'a';
            int pre_dp = dp;
            if (last[idx] == -1)
                dp = dp * 2 + 1;
            else
                dp = dp * 2 - last[idx];
            dp %= MOD;
            dp = (dp < 0 ? dp + MOD : dp);
            last[idx] = pre_dp;
        }
        return dp;
    }
};

int main()
{
    io;
    Solution s;
    string str = "abc";
    cout << s.distinctSubseqII(str) << endl;
    return 0;
}