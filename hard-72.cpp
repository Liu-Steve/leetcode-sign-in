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
    int minDistance(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        int dp[l2 + 1];
        for (int i = 0; i <= l2; ++i)
            dp[i] = i;
        for (int i = 1; i <= l1; ++i)
        {
            int pre = i - 1;
            dp[0] = i;
            for (int j = 1; j <= l2; ++j)
            {
                int newdp;
                if (word1[i - 1] == word2[j - 1])
                    newdp = pre;
                else
                    newdp = 1 + min(pre, min(dp[j], dp[j - 1]));
                pre = dp[j];
                dp[j] = newdp;
            }
        }
        return dp[l2];
    }
};

int main()
{
    io;
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    return 0;
}