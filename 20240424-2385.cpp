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
    int amountOfTime(TreeNode *root, int start)
    {
        vector<TreeNode *> fa(100009);
        TreeNode *p_start = nullptr;
        function<void(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root->val == start)
                p_start = root;
            if (root->left != nullptr)
            {
                fa[root->left->val] = root;
                dfs(root->left);
            }
            if (root->right != nullptr)
            {
                fa[root->right->val] = root;
                dfs(root->right);
            }
        };
        dfs(root);
        int ans = 0;
        vector<bool> vis(100009);
        function<void(TreeNode *, int)> dfs2 = [&](TreeNode *root, int depth)
        {
            if (root == nullptr || vis[root->val])
                return;
            vis[root->val] = true;
            ans = max(ans, depth);
            dfs2(root->left, depth + 1);
            dfs2(root->right, depth + 1);
            dfs2(fa[root->val], depth + 1);
        };
        dfs2(p_start, 0);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
