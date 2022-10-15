#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef struct st
{
    int color;
    bool vis;
    vector<int> *next;
    st()
    {
        color = 0;
        vis = false;
        next = new vector<int>();
    }
} ST;

class Solution
{
private:
    ST *node;

    bool bfs(int idx)
    {
        node[idx].color = 1;
        queue<int> q;
        q.push(idx);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (int nx : *(node[t].next))
            {
                if (!node[nx].vis)
                {
                    node[nx].vis = true;
                    node[nx].color = -node[t].color;
                    q.push(nx);
                }
                if (node[nx].color == node[t].color)
                    return false;
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        node = new ST[n + 1]();
        int len = dislikes.size();
        for (int i = 0; i < len; ++i)
        {
            int n1 = dislikes[i][0], n2 = dislikes[i][1];
            node[n1].next->emplace_back(n2);
            node[n2].next->emplace_back(n1);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (node[i].color != 0)
                continue;
            bool ret = bfs(i);
            if (!ret)
                return false;
        }
        return true;
    }
};

int main()
{
    io;
    Solution s;
    vector<vector<int>> dis = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    cout << s.possibleBipartition(5, dis) << endl;
    return 0;
}