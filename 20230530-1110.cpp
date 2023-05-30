#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool dfs(
        vector<TreeNode *> &ans,
        TreeNode *root,
        const unordered_set<int> &to_delete)
    {
        if (root == nullptr)
            return false;
        bool bl = dfs(ans, root->left, to_delete);
        bool br = dfs(ans, root->right, to_delete);
        if (to_delete.count(root->val))
        {
            if (bl)
                ans.emplace_back(root->left);
            if (br)
                ans.emplace_back(root->right);
            delete root;
            return false;
        }
        else
        {
            if (!bl)
                root->left = nullptr;
            if (!br)
                root->right = nullptr;
        }
        return true;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;

        unordered_set<int> dset;
        for (int num : to_delete)
            dset.emplace(num);

        if (dfs(ans, root, dset))
            ans.emplace_back(root);

        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
