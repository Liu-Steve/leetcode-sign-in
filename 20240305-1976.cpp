#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int countPaths(int n, vv &roads)
    {
        vector<vp> nxt(n); // node, edge
        for (vi &r : roads)
        {
            nxt[r[0]].emplace_back(r[1], r[2]);
            nxt[r[1]].emplace_back(r[0], r[2]);
        }
        // dijkstra
        vb vis(n);
        vl dis(n, INT64_MAX);
        vl ways(n);
        priority_queue<pr, vp, greater<pr>> pq; // dis, node
        pq.emplace(0, 0);
        dis[0] = 0;
        ways[0] = 1;
        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = true;
            for (auto [c_node, edge] : nxt[node])
            {
                if (vis[c_node] || d + edge > dis[c_node])
                    continue;
                if (d + edge == dis[c_node])
                {
                    ways[c_node] += ways[node];
                    ways[c_node] %= MOD;
                    continue;
                }
                ways[c_node] = ways[node];
                dis[c_node] = d + edge;
                pq.emplace(dis[c_node], c_node);
            }
        }
        return ways[n - 1];
    }
};

int main()
{
    io;
    return 0;
}
