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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> mp;
        map<int, vector<TreeNode *>> q1;
        map<int, vector<TreeNode *>> q2;
        q1[0].emplace_back(root);
        while (!q1.empty())
        {
            for (auto [col, nds] : q1)
            {
                auto &vcol = mp[col];
                sort(nds.begin(), nds.end(), [&](TreeNode *t1, TreeNode *t2)
                     { return t1->val < t2->val; });
                for (auto p : nds)
                    vcol.push_back(p->val);
                for (TreeNode *p : nds)
                {
                    if (p->left != nullptr)
                        q2[col - 1].emplace_back(p->left);
                    if (p->right != nullptr)
                        q2[col + 1].emplace_back(p->right);
                }
            }
            q1.clear();
            swap(q1, q2);
        }
        vector<vector<int>> ans;
        for (auto &[col, vcol] : mp)
            ans.emplace_back(vcol);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
