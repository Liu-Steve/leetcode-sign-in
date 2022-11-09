#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, const vector<vector<int>>& mines) {
        int grid[n][n], dp[n][n];
        memset(grid, 0x7f, sizeof(grid));
        memset(dp, 0, sizeof(dp));
        for (vector<int> v : mines) {
            grid[v[0]][v[1]] = 0;
        }
        // cache 友好
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = (i && grid[i][j]) ? (dp[i - 1][j] + 1) : (grid[i][j] > 0);
                grid[i][j] = min(grid[i][j], dp[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = (j && grid[i][j]) ? (dp[i][j - 1] + 1) : (grid[i][j] > 0);
                grid[i][j] = min(grid[i][j], dp[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = ((n - 1 - i) && grid[i][j]) ? (dp[i + 1][j] + 1) : (grid[i][j] > 0);
                grid[i][j] = min(grid[i][j], dp[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = ((n - 1 - j) && grid[i][j]) ? (dp[i][j + 1] + 1) : (grid[i][j] > 0);
                grid[i][j] = min(grid[i][j], dp[i][j]);
            }
        }
        int ret = grid[0][0];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ret = max(ret, grid[i][j]);
        return ret;
    }
};

int main() {
    io;
    Solution s;
    vector<vector<int>> mines = {{3, 0}, {3, 3}};
    cout << s.orderOfLargestPlusSign(5, mines) << endl;
    return 0;
}