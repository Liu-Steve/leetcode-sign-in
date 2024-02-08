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

typedef pair<int, TreeNode *> ret;

class Solution
{
private:
    ret dfs(TreeNode *root, int target, int d)
    {
        if (root->left != nullptr)
        {
            if (root->left->val == target)
                return ret{d, root};
            ret r = dfs(root->left, target, d + 1);
            if (r.first != -1)
                return r;
        }
        if (root->right != nullptr)
        {
            if (root->right->val == target)
                return ret{d, root};
            ret r = dfs(root->right, target, d + 1);
            if (r.first != -1)
                return r;
        }
        return {-1, nullptr};
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        ret rx = dfs(root, x, 0);
        ret ry = dfs(root, y, 0);
        return rx.first != -1 && rx.first == ry.first && rx.second != ry.second;
    }
};

int main()
{
    io;
    return 0;
}
