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
    int ans;
    pr dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {INT32_MAX, -1};
        pr ret = {root->val, root->val};
        pr p1 = dfs(root->left);
        pr p2 = dfs(root->right);
        ret.first = min(ret.first, p1.first);
        ret.first = min(ret.first, p2.first);
        ret.second = max(ret.second, p1.second);
        ret.second = max(ret.second, p2.second);
        ans = max(ans, root->val - ret.first);
        ans = max(ans, ret.second - root->val);
        return ret;
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}