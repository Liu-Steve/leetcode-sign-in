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

struct TrieNode
{
    unordered_map<string, TrieNode *> son;
    string name;
    bool deleted = false;
};

class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        TrieNode *root = new TrieNode();
        for (auto &path : paths)
        {
            TrieNode *cur = root;
            for (auto &s : path)
            {
                if (!cur->son.count(s))
                    cur->son[s] = new TrieNode();
                cur = cur->son[s];
                cur->name = s;
            }
        }
        unordered_map<string, TrieNode *> expr_to_node;
        auto gen_expr = [&](auto &&gen_expr, TrieNode *node) -> string
        {
            if (node->son.empty())
                return node->name;
            vector<string> expr;
            for (auto &[_, son] : node->son)
                expr.emplace_back("(" + gen_expr(gen_expr, son) + ")");
            sort(expr.begin(), expr.end());
            string sub_tree_expr;
            for (auto &e : expr)
                sub_tree_expr += e;
            if (expr_to_node.contains(sub_tree_expr))
            {
                expr_to_node[sub_tree_expr]->deleted = true;
                node->deleted = true;
            }
            else
                expr_to_node[sub_tree_expr] = node;
            return node->name + sub_tree_expr;
        };
        for (auto &[_, son] : root->son)
            gen_expr(gen_expr, son);
        vector<vector<string>> ans;
        vector<string> path;
        auto dfs = [&](auto &&dfs, TrieNode *node) -> void
        {
            if (node->deleted)
                return;
            path.push_back(node->name);
            ans.push_back(path);
            for (auto &[_, son] : node->son)
                dfs(dfs, son);
            path.pop_back();
        };
        for (auto &[_, son] : root->son)
            dfs(dfs, son);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
