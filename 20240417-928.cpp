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
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();
        unordered_map<int, int> ans;
        vector<bool> vis(n);
        for (int i : initial)
            ans[i] = 0;
        int sta = -1;
        function<int(int)> dfs = [&](int root) -> int
        {
            if (ans.count(root))
            {
                if (sta == -1 || sta == root)
                    sta = root;
                else
                    sta = -2;
                return 0;
            }
            vis[root] = true;
            int ret = 1;
            for (int i = 0; i < n; ++i)
                if (!vis[i] && graph[root][i])
                    ret += dfs(i);
            return ret;
        };
        for (int i = 0; i < n; ++i)
        {
            if (vis[i] || ans.count(i))
                continue;
            sta = -1;
            int ret = dfs(i);
            if (sta > 0)
                ans[sta] += ret;
        }
        int node = -1;
        int cnt = -1;
        for (auto [k, v] : ans)
            if (cnt < v || cnt == v && node > k)
            {
                node = k;
                cnt = v;
            }
        return node;
    }
};

int main()
{
    io;
    return 0;
}
