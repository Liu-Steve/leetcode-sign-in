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

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<int> node2net(c + 1, -1);
        vector<set<int>> net2node;
        vector<vector<int>> nxt(c + 1);
        for (auto &con : connections)
        {
            nxt[con[0]].push_back(con[1]);
            nxt[con[1]].push_back(con[0]);
        }
        auto dfs = [&](auto &&dfs, int node, int fa) -> void
        {
            if (node2net[node] != -1)
                return;
            if (fa == -1)
                net2node.emplace_back();
            net2node.back().insert(node);
            node2net[node] = net2node.size() - 1;
            for (int chd : nxt[node])
                dfs(dfs, chd, node);
        };
        for (int i = 1; i <= c; ++i)
            dfs(dfs, i, -1);
        vector<int> ans;
        for (auto &q : queries)
        {
            int net = node2net[q[1]];
            if (q[0] == 2)
            {
                net2node[net].erase(q[1]);
                continue;
            }
            if (net2node[net].count(q[1]))
                ans.push_back(q[1]);
            else if (net2node[net].size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(*net2node[net].begin());
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
