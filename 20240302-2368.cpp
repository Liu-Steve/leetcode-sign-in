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
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<bool> r(n);
        for (int node : restricted)
            r[node] = true;
        vector<vector<int>> nxt(n);
        for (auto &e : edges)
        {
            if (r[e[0]] || r[e[1]])
                continue;
            nxt[e[0]].push_back(e[1]);
            nxt[e[1]].push_back(e[0]);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int root, int par) -> void
        {
            ans++;
            for (int c : nxt[root])
                if (c != par)
                    dfs(c, root);
        };
        dfs(0, -1);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
