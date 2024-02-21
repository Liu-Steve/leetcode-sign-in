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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            mp[inorder[i]] = i;
        function<TreeNode *(int, int, int)> dfs = [&](int pp, int ip, int num) -> TreeNode *
        {
            if (num <= 0)
                return nullptr;
            TreeNode *root = new TreeNode(postorder[pp - 1 + num]);
            int irp = mp[root->val];
            root->left = dfs(pp, ip, irp - ip);
            root->right = dfs(pp + irp - ip, irp + 1, num - irp + ip - 1);
            return root;
        };
        return dfs(0, 0, n);
    }
};

int main()
{
    io;
    return 0;
}
