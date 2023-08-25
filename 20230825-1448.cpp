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
    int dfs(TreeNode *root, int mx)
    {
        if (root == nullptr)
            return 0;
        int ans = (root->val >= mx);
        mx = max(mx, root->val);
        ans += dfs(root->left, mx);
        ans += dfs(root->right, mx);
        return ans;
    }

public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, root->val);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
