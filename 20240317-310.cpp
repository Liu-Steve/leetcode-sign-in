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
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vi findMinHeightTrees(int n, vv &edges)
    {
        vv nxt(n);
        for (vi &e : edges)
        {
            nxt[e[0]].emplace_back(e[1]);
            nxt[e[1]].emplace_back(e[0]);
        }
        vi parents(n);
        function<pr(int, int, int)> dfs = [&](int root, int par, int now) -> pr
        {
            pr ans{root, now};
            parents[root] = par;
            for (int ch : nxt[root])
            {
                if (ch == par)
                    continue;
                auto [node, deepth] = dfs(ch, root, now + 1);
                if (deepth > ans.second)
                    ans = pr{node, deepth};
            }
            return ans;
        };
        auto [x, dx] = dfs(0, -1, 1);
        auto [y, dy] = dfs(x, -1, 1);
        vi path;
        while (y != -1)
        {
            path.push_back(y);
            y = parents[y];
        }
        if (dy % 2 == 1)
            return vi{path[dy / 2]};
        else
            return vi{path[dy / 2 - 1], path[dy / 2]};
    }
};

int main()
{
    io;
    return 0;
}
