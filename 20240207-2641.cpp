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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
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
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        vector<TreeNode *> q = {root};
        root->val = 0;
        while (!q.empty())
        {
            vector<TreeNode *> q2;
            int sum = 0;
            for (auto fa : q)
            {
                if (fa->left)
                {
                    q2.push_back(fa->left);
                    sum += fa->left->val;
                }
                if (fa->right)
                {
                    q2.push_back(fa->right);
                    sum += fa->right->val;
                }
            }
            for (auto fa : q)
            {
                int child_sum = (fa->left ? fa->left->val : 0) +
                                (fa->right ? fa->right->val : 0);
                if (fa->left)
                    fa->left->val = sum - child_sum;
                if (fa->right)
                    fa->right->val = sum - child_sum;
            }
            q = move(q2);
        }
        return root;
    }
};

int main()
{
    io;
    return 0;
}
