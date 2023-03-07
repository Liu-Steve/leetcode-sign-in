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
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<ll, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        for (int i = 0;i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                int l = j == 0 ? 0 : grid[i][j - 1];
                int r = i == 0 ? 0 : grid[i - 1][j];
                grid[i][j] += max(l, r);
            }
        }
        return grid[x - 1][y - 1];
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}