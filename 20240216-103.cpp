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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<TreeNode *> q1;
        vector<TreeNode *> q2;
        if (root != nullptr)
            q1.push_back(root);
        while (!q1.empty())
        {
            ans.emplace_back();
            for (auto p : q1)
            {
                ans.back().push_back(p->val);
                if (p->left != nullptr)
                    q2.push_back(p->left);
                if (p->right != nullptr)
                    q2.push_back(p->right);
            }
            q1.clear();
            swap(q1, q2);
        }
        for (int i = 1; i < ans.size(); i += 2)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
