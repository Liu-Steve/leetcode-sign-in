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
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> nxt(n);
        for (auto &e : edges)
        {
            nxt[e[0]].push_back(e[1]);
            nxt[e[1]].push_back(e[0]);
        }
        auto h = [&](long long u, long long v) -> long long
        {
            return (u << 32) | v;
        };
        unordered_set<long long> s;
        for (auto &g : guesses)
            s.insert(h(g[0], g[1]));
        int cnt = 0;
        function<void(int, int)> dfs1 = [&](int root, int parent)
        {
            cnt += s.count(h(parent, root));
            for (int c : nxt[root])
                if (c != parent)
                    dfs1(c, root);
        };
        dfs1(0, INT32_MAX);
        int ans = 0;
        function<void(int, int, int)> dfs2 = [&](int root, int parent, int corr)
        {
            if (s.count(h(parent, root)))
                corr--;
            if (s.count(h(root, parent)))
                corr++;
            if (corr >= k)
                ans++;
            for (int c : nxt[root])
                if (c != parent)
                    dfs2(c, root, corr);
        };
        dfs2(0, INT32_MAX, cnt);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
