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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = nullptr;
        function<pair<bool, bool>(TreeNode *)> dfs = [&](TreeNode *root) -> pair<bool, bool>
        {
            if (root == nullptr)
                return pair<bool, bool>{false, false};
            bool bl = (root == p);
            bool br = (root == q);
            auto [bll, blr] = dfs(root->left);
            auto [brl, brr] = dfs(root->right);
            cout << root->val << endl;
            if (bl && (blr || brr) || br && (bll || brl) || bll && brr || blr && brl)
                ans = root;
            return pair<bool, bool>{bl || bll || brl, br || blr || brr};
        };
        dfs(root);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
