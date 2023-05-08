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
typedef unordered_map<ll, int> memory;

class Solution
{
private:
    inline int hh(pr b, pr p)
    {
        return (b.first << 15) |
               (b.second << 10) |
               (p.first << 5) |
               (p.second);
    }

public:
    int minPushBox(vector<vc> &grid)
    {
        int m = grid.size() + 2;
        int n = grid[0].size() + 2;
        vector<vc> mp(m, vc(n));
        pr player;
        pr box;
        pr target;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    mp[i][j] = '#';
                    continue;
                }
                if (grid[i - 1][j - 1] == 'S')
                {
                    mp[i][j] = '.';
                    player = {i, j};
                    continue;
                }
                if (grid[i - 1][j - 1] == 'T')
                {
                    mp[i][j] = '.';
                    target = {i, j};
                    continue;
                }
                if (grid[i - 1][j - 1] == 'B')
                {
                    mp[i][j] = '.';
                    box = {i, j};
                    continue;
                }
                mp[i][j] = grid[i - 1][j - 1];
            }
        }

        int bias[5] = {1, 0, -1, 0, 1};

        auto find_dir = [&](pr b, pr p)
        {
            // bfs
            queue<pr> q;
            vector<vc> msk(m, vc(n, '0'));
            msk[b.first][b.second] = '1';
            msk[p.first][p.second] = '1';
            q.emplace(p);
            while (!q.empty())
            {
                pr &f = q.front();
                for (int i = 0; i < 4; ++i)
                {
                    pr newp = {f.first + bias[i], f.second + bias[i + 1]};
                    if (mp[newp.first][newp.second] == '.' && msk[newp.first][newp.second] == '0')
                    {
                        q.push(newp);
                        msk[newp.first][newp.second] = '1';
                    }
                }
                q.pop();
            }
            // can move
            vector<bool> ans(4);
            for (int i = 0; i < 4; ++i)
            {
                pr newp = {b.first + bias[i], b.second + bias[i + 1]};
                pr newb = {b.first - bias[i], b.second - bias[i + 1]};
                ans[i] = msk[newp.first][newp.second] == '1' && mp[newb.first][newb.second] == '.';
            }
            return ans;
        };

        // bfs
        queue<pair<pr, pr>> q1, q2;
        unordered_set<int> vis;
        int step = 0;
        q1.emplace(box, player);
        vis.emplace(hh(box, player));
        while (!q1.empty())
        {
            while (!q1.empty())
            {
                auto &[b, p] = q1.front();
                if (b == target)
                    return step;
                auto dir = find_dir(b, p);
                for (int i = 0; i < 4; ++i)
                {
                    if (!dir[i])
                        continue;
                    pr newp = b;
                    pr newb = {b.first - bias[i], b.second - bias[i + 1]};
                    if (vis.count(hh(newb, newp)))
                        continue;
                    q2.emplace(newb, newp);
                    vis.emplace(hh(newb, newp));
                }
                q1.pop();
            }
            step++;
            swap(q1, q2);
        }

        return -1;
    }
};

int main()
{
    io;
    Solution s;
    vector<vc> v1 = {
        {'#', '#', '#', '#', '#', '#'},
        {'#', 'T', '#', '#', '#', '#'},
        {'#', '.', '.', 'B', '.', '#'},
        {'#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', 'S', '#'},
        {'#', '#', '#', '#', '#', '#'}};
    cout << s.minPushBox(v1) << endl;
    vector<vc> v2 = {
        {'S'}, {'B'}, {'T'}, {'.'}, {'#'}};
    cout << s.minPushBox(v2) << endl;
    return 0;
}
