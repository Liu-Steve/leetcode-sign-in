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

typedef struct st1
{
    int d[2];
    vector<pair<int, bool>> nei[2];
    st1()
    {
        d[0] = d[1] = INT32_MAX;
    }
} NODE;

typedef struct st2
{
    int from;
    int to;
    int color;
    st2(int f, int t, int c) : from(f), to(t), color(c) {}
} EDGE;

class Solution
{
public:
    vi shortestAlternatingPaths(int n, vv &redEdges, vv &blueEdges)
    {
        vector<NODE> ns(n);
        for (vi e : redEdges)
            ns[e[0]].nei[0].emplace_back(e[1], false);
        for (vi e : blueEdges)
            ns[e[0]].nei[1].emplace_back(e[1], false);

        // bfs
        queue<EDGE> q;
        ns[0].d[0] = ns[0].d[1] = 0;
        for (int i = 0; i < 2; ++i)
            for (auto &[to, vis] : ns[0].nei[i])
                if (!vis)
                {
                    q.emplace(0, to, i);
                    vis = true;
                }
        while (!q.empty())
        {
            auto &[from, to, color] = q.front();
            ns[to].d[color] = min(ns[to].d[color], ns[from].d[!color] + 1);
            for (auto &[to2, vis] : ns[to].nei[!color])
                if (!vis)
                {
                    q.emplace(to, to2, !color);
                    vis = true;
                }
            q.pop();
        }

        // result
        vi ans(n);
        for (int i = 0; i < n; ++i)
        {
            int dm = min(ns[i].d[0], ns[i].d[1]);
            if (dm == INT32_MAX)
                ans[i] = -1;
            else
                ans[i] = dm;
        }
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    vv r1 = {{0, 1}, {1, 2}};
    vv b1 = {};
    for (auto i : s.shortestAlternatingPaths(3, r1, b1))
        cout << i << ' ';
    cout << endl;
    vv r2 = {{0, 1}};
    vv b2 = {{2, 1}};
    for (auto i : s.shortestAlternatingPaths(3, r2, b2))
        cout << i << ' ';
    cout << endl;
    vv r3 = {{1, 0}};
    vv b3 = {{2, 1}};
    for (auto i : s.shortestAlternatingPaths(3, r3, b3))
        cout << i << ' ';
    cout << endl;
    vv r4 = {{0, 1}};
    vv b4 = {{1, 2}};
    for (auto i : s.shortestAlternatingPaths(3, r4, b4))
        cout << i << ' ';
    cout << endl;
    vv r5 = {{0, 1}, {0, 2}};
    vv b5 = {{1, 0}};
    for (auto i : s.shortestAlternatingPaths(3, r5, b5))
        cout << i << ' ';
    cout << endl;
    vv r6 = {
        {1, 0},
        {3, 6},
        {5, 0},
        {2, 2},
        {3, 8},
        {6, 0},
        {4, 3},
        {4, 1},
        {6, 2},
        {0, 0},
        {5, 2},
        {7, 8},
        {5, 4},
        {0, 7},
        {1, 2},
        {5, 7},
        {1, 5},
        {3, 3},
        {8, 5},
        {3, 4},
        {5, 5},
        {0, 6},
        {7, 2},
        {2, 1}};
    vv b6 = {
        {3, 2},
        {1, 2},
        {6, 5},
        {5, 2},
        {5, 0},
        {4, 5},
        {6, 6},
        {4, 2},
        {7, 1},
        {4, 1},
        {7, 3},
        {3, 5},
        {8, 7},
        {7, 0},
        {3, 4},
        {7, 6},
        {2, 8},
        {0, 0},
        {0, 6},
        {1, 1},
        {3, 1}};
    for (auto i : s.shortestAlternatingPaths(9, r6, b6))
        cout << i << ' ';
    cout << endl;
    return 0;
}