#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

const int INF = INT32_MAX;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef struct st
{
    int move;
    bool vis;
    vp nei;
    st()
    {
        move = INF;
        vis = false;
    }
} Node;

struct cmp
{
    bool operator()(pr &p1, pr &p2)
    {
        return p1.second > p2.second;
    }
};

class Solution
{
public:
    int reachableNodes(vv &edges, int maxMoves, int n)
    {
        Node node[n];
        node[0].move = 0;
        int m = edges.size();
        for (int i = 0; i < m; ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2] + 1;
            node[u].nei.emplace_back(v, d);
            node[v].nei.emplace_back(u, d);
        }
        ll res = 0;
        // dijkstra
        priority_queue<pr, vector<pr>, cmp> q;
        q.emplace(0, 0);
        while (!q.empty())
        {
            int now = q.top().first;
            q.pop();
            // 过时信息
            if (node[now].vis)
                continue;
            node[now].vis = true;
            int now_move = node[now].move;
            // 剪枝
            if (now_move > maxMoves)
                break;
            else
                res++;
            for (pr nxt : node[now].nei)
            {
                if (node[nxt.first].vis)
                    continue;
                int new_move = now_move + nxt.second;
                if (node[nxt.first].move > new_move)
                {
                    node[nxt.first].move = new_move;
                    q.emplace(nxt.first, new_move);
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            int uadd = maxMoves - node[u].move;
            int vadd = maxMoves - node[v].move;
            res += min(d, (uadd > 0 ? uadd : 0) + (vadd > 0 ? vadd : 0));
        }
        return res;
    }
};

int main()
{
    io;
    Solution s;
    vv v1 = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    cout << s.reachableNodes(v1, 6, 3) << endl;
    vv v2 = {{0, 1, 4}, {1, 2, 6}, {0, 2, 8}, {1, 3, 1}};
    cout << s.reachableNodes(v2, 10, 4) << endl;
    vv v3 = {{1, 2, 4}, {1, 4, 5}, {1, 3, 1}, {2, 3, 4}, {3, 4, 5}};
    cout << s.reachableNodes(v3, 17, 5) << endl;
    vv v4 = {{1, 2, 5}, {0, 3, 3}, {1, 3, 2}, {2, 3, 4}, {0, 4, 1}};
    cout << s.reachableNodes(v4, 7, 5) << endl;
    return 0;
}