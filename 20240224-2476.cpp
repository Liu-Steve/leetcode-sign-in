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
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<int> nums;
        function<void(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root == nullptr)
                return;
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        vector<vector<int>> ans;
        for (int q : queries)
        {
            vector<int> qans = {0, 0};
            auto it = upper_bound(nums.begin(), nums.end(), q);
            qans[0] = (it != nums.begin() ? *(it - 1) : -1);
            it = lower_bound(nums.begin(), nums.end(), q);
            qans[1] = (it != nums.end() ? *it : -1);
            ans.push_back(qans);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
