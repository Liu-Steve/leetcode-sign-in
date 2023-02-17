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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dp[2][n][m];
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
            {
                dp[0][j][k] = grid[j][k];
                if (j > 0 && grid[j][k])
                    dp[0][j][k] += dp[0][j - 1][k];
            }
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
            {
                dp[1][j][k] = grid[j][k];
                if (k > 0 && grid[j][k])
                    dp[1][j][k] += dp[1][j][k - 1];
            }
        int ans = min(n, m);
        while (ans--)
        {
            for (int j = 0; j < n - ans; ++j)
                for (int k = 0; k < m - ans; ++k)
                {
                    int e = min(
                        {dp[0][j + ans][k + ans],
                         dp[1][j + ans][k + ans],
                         dp[0][j + ans][k],
                         dp[1][j][k + ans]});
                    if (e > ans)
                        return (ans + 1) * (ans + 1);
                }
        }
        return 0;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << s.largest1BorderedSquare(v1) << endl;
    vv v2 = {{1, 1, 0, 0}};
    cout << s.largest1BorderedSquare(v2) << endl;
    vv v3 = {{0, 0}};
    cout << s.largest1BorderedSquare(v3) << endl;
    vv v4 = {{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 1, 1}};
    cout << s.largest1BorderedSquare(v4) << endl;
    return 0;
}