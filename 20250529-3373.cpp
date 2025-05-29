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

const long long MOD = 1000000007LL;

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> tree1(n);
        vector<vector<int>> tree2(m);
        for (auto &e : edges1)
        {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }
        vector<int> color1(n, -1);
        vector<int> color2(m, -1);
        auto dfs = [&](auto &&dfs, vector<vector<int>> &tree, vector<int> &color, int node, int fa, int c) -> void
        {
            color[node] = c;
            for (int ch : tree[node])
            {
                if (ch == fa)
                    continue;
                dfs(dfs, tree, color, ch, node, !c);
            }
        };
        dfs(dfs, tree1, color1, 0, -1, 0);
        dfs(dfs, tree2, color2, 0, -1, 0);
        int sum1 = accumulate(color1.begin(), color1.end(), 0);
        int sum2 = accumulate(color2.begin(), color2.end(), 0);
        sum2 = max(sum2, m - sum2);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            if (color1[i])
                ans[i] = sum1 + sum2;
            else
                ans[i] = n - sum1 + sum2;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
