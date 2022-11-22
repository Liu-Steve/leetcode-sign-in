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

inline double ed(int i, int j)
{
    if (i <= 0 && j <= 0)
        return 0.5;
    if (i <= 0)
        return 1;
    return 0;
}

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4451)
            return 1;
        int u = ceil(n / 25.0);
        double dp[u + 1][u + 1];
        for (int i = 0; i <= u; ++i)
        {
            dp[i][0] = ed(i, 0);
            dp[0][i] = ed(0, i);
        }
        for (int i = 1; i <= u; ++i)
        {
            for (int j = 1; j <= u; ++j)
            {
                dp[i][j] = 0.25 * (
                    (i - 4 >= 0 && j >= 0 ? dp[i - 4][j] : ed(i - 4, j)) + 
                    (i - 3 >= 0 && j - 1 >= 0 ? dp[i - 3][j - 1] : ed(i - 3, j - 1)) + 
                    (i - 2 >= 0 && j - 2 >= 0 ? dp[i - 2][j - 2] : ed(i - 2, j - 2)) + 
                    (i - 1 >= 0 && j - 3 >= 0 ? dp[i - 1][j - 3] : ed(i - 1, j - 3)));
            }
        }
        return dp[u][u];
    }
};

int main() {
    io;
    Solution s;
    cout << setprecision(10) << s.soupServings(4451) << endl;
    return 0;
}