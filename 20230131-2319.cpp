#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if ((i == j || i + j == n - 1) ^ (bool)grid[i][j])
                    return false;
        return true;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{2, 0, 0, 1}, {0, 3, 1, 0}, {0, 5, 2, 0}, {4, 0, 0, 2}};
    cout << s.checkXMatrix(v1) << endl;
    vv v2 = {{5, 7, 0}, {0, 3, 1}, {0, 5, 0}};
    cout << s.checkXMatrix(v2) << endl;
    return 0;
}