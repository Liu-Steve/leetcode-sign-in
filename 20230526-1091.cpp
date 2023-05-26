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
public:
    int shortestPathBinaryMatrix(vv &grid)
    {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        vv msk(n + 2, vi(n + 2, 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                msk[i + 1][j + 1] = grid[i][j];

        // bfs
        vi b = {1, 1, 0, 1, -1, -1, 0, -1, 1};
        queue<pr> q1, q2;
        int ans = 1;
        q1.emplace(1, 1);
        msk[0][0] = 1;
        while (!q1.empty())
        {
            while (!q1.empty())
            {
                auto [x, y] = q1.front();
                q1.pop();
                if (x == n && y == n)
                    return ans;
                for (int i = 0; i < 8; ++i)
                    if (msk[x + b[i]][y + b[i + 1]] == 0)
                    {
                        msk[x + b[i]][y + b[i + 1]] = 1;
                        q2.emplace(x + b[i], y + b[i + 1]);
                    }
            }
            swap(q1, q2);
            ans++;
        }

        return -1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
