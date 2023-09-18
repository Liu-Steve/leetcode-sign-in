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
    pair<int, int> robs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        auto p1 = robs(root->left);
        auto p2 = robs(root->right);
        int a1 = root->val + p1.second + p2.second;
        int a2 = max(p1.first, p1.second) + max(p2.first, p2.second);
        return {a1, a2};
    }

public:
    int rob(TreeNode *root)
    {
        auto ans = robs(root);
        return max(ans.first, ans.second);
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
