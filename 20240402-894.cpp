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

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

#define MOD 1000000007LL

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return vector<TreeNode *>{};
        vector<vector<TreeNode *>> dp(n / 2 + 1);
        dp[0].emplace_back(new TreeNode());
        for (int i = 1; i <= n / 2; ++i)
        {
            for (int j = 0; j < i; j++)
            {
                vector<TreeNode *> &sub_l = dp[j];
                vector<TreeNode *> &sub_r = dp[i - j - 1];
                for (auto l : sub_l)
                    for (auto r : sub_r)
                        dp[i].emplace_back(new TreeNode(0, l, r));
            }
        }
        return dp.back();
    }
};

int main()
{
    io;
    return 0;
}
