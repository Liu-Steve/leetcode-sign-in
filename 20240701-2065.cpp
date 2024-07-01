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
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> nxt(n);
        for (auto &e : edges)
        {
            nxt[e[0]].emplace_back(e[1], e[2]);
            nxt[e[1]].emplace_back(e[0], e[2]);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        function<void(int, int, int)> dfs = [&](int node, int time, int sum)
        {
            if (time < 0)
                return;
            if (vis[node] == 0)
                sum += values[node];
            vis[node]++;
            if (node == 0)
                ans = max(ans, sum);
            for (auto [nnode, t] : nxt[node])
                dfs(nnode, time - t, sum);
            vis[node]--;
            if (vis[node] == 0)
                sum -= values[node];
        };
        dfs(0, maxTime, 0);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
