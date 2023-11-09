#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
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
    int maximumMinutes(vv &grid)
    {
        const int b[5] = {1, 0, -1, 0, 1};
        int m = grid.size();
        int n = grid[0].size();
        auto bfs = [&](vp &q1) -> tuple<int, int, int>
        {
            vv dis(m, vi(n, -1));
            int d = 1;
            for (auto [x, y] : q1)
                dis[x][y] = 0;
            while (!q1.empty())
            {
                vp q2;
                for (auto [x, y] : q1)
                    for (int i = 0; i < 4; ++i)
                    {
                        int nx = x + b[i];
                        int ny = y + b[i + 1];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (dis[nx][ny] == -1 && grid[nx][ny] == 0)
                        {
                            dis[nx][ny] = d;
                            q2.emplace_back(nx, ny);
                        }
                    }
                d++;
                q1 = move(q2);
            }
            return {dis[m - 1][n - 1], dis[m - 2][n - 1], dis[m - 1][n - 2]};
        };

        vp qm = {{0, 0}};
        auto [mm, m1, m2] = bfs(qm);
        if (mm < 0)
            return -1;

        vp qf;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    qf.emplace_back(i, j);
        auto [f, f1, f2] = bfs(qf);
        if (f < 0)
            return 1000000000;

        int d = f - mm;
        if (d < 0)
            return -1;
        if (m1 != -1 && m1 + d < f1 || m2 != -1 && m2 + d < f2)
            return d;
        return d - 1;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
