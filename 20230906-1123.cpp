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
    TreeNode *dfs(TreeNode *root, int &h)
    {
        if (root == nullptr)
        {
            h = 0;
            return nullptr;
        }
        int h1, h2;
        TreeNode *t1 = dfs(root->left, h1);
        TreeNode *t2 = dfs(root->right, h2);
        h = max(h1, h2) + 1;
        if (h1 > h2)
            return t1;
        else if (h1 < h2)
            return t2;
        else
            return root;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        int h;
        return dfs(root, h);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
