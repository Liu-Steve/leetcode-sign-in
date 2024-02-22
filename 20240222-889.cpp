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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        map<int, int> mp;
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
            mp[postorder[i]] = i;
        function<TreeNode *(int, int, int)> dfs = [&](int p1, int p2, int num) -> TreeNode *
        {
            if (num <= 0)
                return nullptr;
            TreeNode *root = new TreeNode(preorder[p1]);
            if (num == 1)
                return root;
            int irp = mp[preorder[p1 + 1]];
            root->left = dfs(p1 + 1, p2, irp - p2 + 1);
            root->right = dfs(p1 + irp - p2 + 2, irp + 1, num - irp + p2 - 2);
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
