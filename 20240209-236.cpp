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
private:
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;
    pair<bool, bool> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return pair<bool, bool>{false, false};
        auto [lp, lq] = dfs(root->left);
        auto [rp, rq] = dfs(root->right);
        if (lp && rq || lq && rp || (root == p) && (lq || rq) || (root == q) && (lp || rp))
            ans = root;
        return pair<bool, bool>{lp || rp || (root == p), lq || rq || (root == q)};
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *pp, TreeNode *qq)
    {
        p = pp;
        q = qq;
        ans = nullptr;
        dfs(root);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
