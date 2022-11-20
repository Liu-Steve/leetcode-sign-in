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
    double champagneTower(int k, int r, int c)
    {
        if(r == 0)
            return min(1, k);
        double dp[r + 1];
        dp[0] = k;
        for (int i = 1; i < r; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                double ldp = (j > 0 && dp[j - 1] > 1) ? (dp[j - 1] - 1) / 2 : 0;
                double rdp = (j < i && dp[j] > 1) ? (dp[j] - 1) / 2 : 0;
                dp[j] = ldp + rdp;
            }
        }
        double ldp = (c > 0 && dp[c - 1] > 1) ? (dp[c - 1] - 1) / 2 : 0;
        double rdp = (c < r && dp[c] > 1) ? (dp[c] - 1) / 2 : 0;
        return min(1.0, ldp + rdp);
    }
};

int main()
{
    io;
    Solution s;
    cout << s.champagneTower(1, 1, 1) << endl;
    cout << s.champagneTower(2, 1, 0) << endl;
    cout << s.champagneTower(8, 3, 3) << endl;
    cout << s.champagneTower(100000009, 33, 17) << endl;
    return 0;
}