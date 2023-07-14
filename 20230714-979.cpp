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
    tuple<int, int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return make_tuple(0, 0, 0);
        auto [ans1, sum1, val1] = dfs(root->left);
        auto [ans2, sum2, val2] = dfs(root->right);
        int sum = sum1 + sum2 + 1;
        int val = val1 + val2 + root->val;
        return make_tuple(ans1 + ans2 + abs(sum - val), sum, val);
    }

public:
    int distributeCoins(TreeNode *root)
    {
        auto [ans, sum, val] = dfs(root);
        return ans;
    }
};

int main()
{
    io;
    Solution s;
    return 0;
}
