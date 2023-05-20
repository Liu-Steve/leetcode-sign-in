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
typedef unordered_map<ll, int> memory;

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
    int ans = 0;
    tuple<int, int, bool, int> dfs(TreeNode *root)
    {
        int l;
        int r;
        bool valid = true;
        int sum = root->val;

        if (root->left == nullptr)
        {
            l = root->val;
        }
        else
        {
            auto [sl, sr, sv, ss] = dfs(root->left);
            if (!sv || sr >= root->val)
                valid = false;
            l = min(sl, root->val);
            sum += ss;
        }

        if (root->right == nullptr)
        {
            r = root->val;
        }
        else
        {
            auto [sl, sr, sv, ss] = dfs(root->right);
            if (!sv || sl <= root->val)
                valid = false;
            r = max(sr, root->val);
            sum += ss;
        }

        if (valid)
            ans = max(ans, sum);

        return make_tuple(l, r, valid, sum);
    }

public:
    int maxSumBST(TreeNode *root)
    {
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
