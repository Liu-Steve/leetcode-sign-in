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
        vector<bool> ini(n);
        vector<bool> vis(n);
        for (int i : initial)
            ini[i] = true;
        int cnt = 0;
        function<int(int)> dfs = [&](int root) -> int
        {
            vis[root] = true;
            cnt += ini[root];
            int ret = 1;
            for (int i = 0; i < n; ++i)
                if (!vis[i] && graph[root][i])
                    ret += dfs(i);
            return ret;
        };
        int ans = -1;
        int idx = -1;
        for (int i : initial)
        {
            cnt = 0;
            vis.assign(n, false);
            int ret = dfs(i);
            if (cnt != 1)
                ret = 0;
            if (ret < ans || ret == ans && i > idx)
                continue;
            ans = ret;
            idx = i;
        }
        return idx;
    }
};

int main()
{
    io;
    return 0;
}
