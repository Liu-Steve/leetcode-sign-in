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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<pair<int, int>>> nxt(n + 1);
        for (int i = 0; i < n; ++i)
        {
            auto &e = edges[i];
            nxt[e[0]].emplace_back(e[1], i);
            nxt[e[1]].emplace_back(e[0], i);
        }
        vector<int> st;
        vector<bool> vis(n + 1);
        int start = -1;
        auto dfs = [&](auto &&dfs, int root, int fa, int idx) -> bool
        {
            st.push_back(idx);
            if (vis[root])
            {
                start = root;
                return true;
            }
            vis[root] = true;
            for (auto [child, id] : nxt[root])
            {
                if (child == fa)
                    continue;
                if (dfs(dfs, child, root, id))
                    return true;
            }
            vis[root] = false;
            st.pop_back();
            return false;
        };
        dfs(dfs, 1, -1, -1);
        int ans = st.back();
        int m = st.size();
        for (int i = m - 2; i >= 0; --i)
        {
            ans = max(ans, st[i]);
            if (edges[st[i]][0] == start || edges[st[i]][1] == start)
                break;
        }
        return edges[ans];
    }
};

int main()
{
    io;
    return 0;
}
