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
private:
    int n;
    int m;
    int b[9] = {1, 1, 0, -1, -1, 0, 1, -1, 1};
    int dfs(int x, int y, vector<vector<int>> &land)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return 0;
        if (land[x][y] != 0)
            return 0;
        land[x][y] = 1;
        int ret = 1;
        for (int i = 0; i < 8; ++i)
            ret += dfs(x + b[i], y + b[i + 1], land);
        return ret;
    }

public:
    vector<int> pondSizes(vector<vector<int>> &land)
    {
        vector<int> ans;
        n = land.size();
        m = land[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (land[i][j] == 0)
                    ans.emplace_back(dfs(i, j, land));
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
