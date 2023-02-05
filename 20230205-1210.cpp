#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;

class Solution
{
private:
    static int hash(int x, int y, bool down)
    {
        return (x << 8) | (y << 1) | down;
    }

    static auto dehash(int h)
    {
        int x = h >> 8;
        int y = (h >> 1) & 127;
        bool down = h & 1;
        return make_tuple(x, y, down);
    }

public:
    int minimumMoves(vv &grid)
    {
        int n = grid.size();
        queue<int> q1, q2;
        hm vis;
        int end = hash(n - 1, n - 2, false);
        q1.emplace(hash(0, 0, false));

        // bfs
        for (int step = 0;; ++step)
        {
            while (!q1.empty())
            {
                int h = q1.front();
                q1.pop();
                // success
                if (h == end)
                    return step;
                // has tried
                if (!vis.insert(h).second)
                    continue;
                auto [x, y, down] = dehash(h);

                // move straight
                if (x + down + down < n &&
                    y + !down + !down < n &&
                    !grid[x + down + down][y + !down + !down])
                    q2.emplace(hash(x + down, y + !down, down));
                // side filled
                if (x + 1 >= n ||
                    y + 1 >= n ||
                    grid[x + !down][y + down] ||
                    grid[x + 1][y + 1])
                    continue;
                // move side
                q2.emplace(hash(x + !down, y + down, down));
                // turn
                q2.emplace(hash(x, y, !down));
            }

            if (q2.empty())
                break;
            swap(q1, q2);
        }
        return -1;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{0, 0, 0, 0, 0, 1},
             {1, 1, 0, 0, 1, 0},
             {0, 0, 0, 0, 1, 1},
             {0, 0, 1, 0, 1, 0},
             {0, 1, 1, 0, 0, 0},
             {0, 1, 1, 0, 0, 0}};
    cout << s.minimumMoves(v1) << endl;
    vv v2 = {{0, 0, 1, 1, 1, 1},
             {0, 0, 0, 0, 1, 1},
             {1, 1, 0, 0, 0, 1},
             {1, 1, 1, 0, 0, 1},
             {1, 1, 1, 0, 0, 1},
             {1, 1, 1, 0, 0, 0}};
    cout << s.minimumMoves(v2) << endl;
    vv v3 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
             {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
             {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
             {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
             {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
             {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
             {0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
             {0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    cout << s.minimumMoves(v3) << endl;
    return 0;
}