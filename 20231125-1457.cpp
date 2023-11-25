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
    map<int, int> cnt;
    int odd = 0;
    int ans = 0;
    void dfs(TreeNode *root)
    {
        int val = root->val;
        cnt[val]++;
        odd += (cnt[val] % 2 ? 1 : -1);
        if (root->left == nullptr && root->right == nullptr)
            ans += (odd < 2);
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        odd -= (cnt[val] % 2 ? 1 : -1);
        cnt[val]--;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
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
