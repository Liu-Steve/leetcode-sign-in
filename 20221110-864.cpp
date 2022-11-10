#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef pair<int, int> pr;

typedef struct st
{
    pr point;
    int key;
    int step;
    st (pr p, int k, int s) {
        point = p;
        key = k;
        step = s;
    }
} STA;

inline bool isLocked(char ch, int key_set)
{
    return (ch >= 'A' && ch <= 'F' && !(key_set & (1 << (ch - 'A'))));
}

inline int hash_sta(pr point, int key) {
    return point.first | (point.second << 5) | (key << 10);
}

const int dir[5] = {1, 0, -1, 0, 1};

class Solution
{
public:
    int shortestPathAllKeys(const vector<string> &grid)
    {
        // 找到开始点与钥匙数
        int full = 0;
        pr start;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char ch = grid[i][j];
                if (ch == '@')
                    start = {i, j};
                else if (ch >= 'a' && ch <= 'f')
                    full |= 1 << (ch - 'a');
            }
        }
        // bfs
        queue<STA> q;
        unordered_set<int> visited;
        q.emplace(start, 0, 0);
        visited.insert(hash_sta(start, 0));
        while (!q.empty())
        {
            STA now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                // 越界
                int x = now.point.first + dir[i];
                int y = now.point.second + dir[i + 1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                char ch = grid[x][y];
                pr new_point = {x, y};
                int key = now.key;
                int step = now.step + 1;
                // 判墙
                if (ch == '#')
                    continue;
                if (isLocked(ch, key))
                    continue;
                // 拿钥匙
                if (ch >= 'a' && ch <= 'f')
                    key |= 1 << (ch - 'a');
                if (key == full)
                    return step;
                // 判重
                if (!visited.insert(hash_sta(new_point, key)).second)
                    continue;
                q.emplace(new_point, key, step);
            }
        }
        return -1;
    }
};

int main()
{
    io;
    Solution s;
    vector<string> grid = {"@Aa"};
    cout << s.shortestPathAllKeys(grid) << endl;
    return 0;
}