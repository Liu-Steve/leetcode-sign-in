#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
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
    void dfs(TreeNode *root1, TreeNode *root2, bool o)
    {
        if (root1 == nullptr)
            return;
        if (o)
            swap(root1->val, root2->val);
        dfs(root1->left, root2->right, !o);
        dfs(root1->right, root2->left, !o);
    }

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, true);
        return root;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
