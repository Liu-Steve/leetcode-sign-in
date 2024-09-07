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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    int maximumLength(vi &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, vi> dp;
        vi zd(k + 1);

        for (int i = 0; i < n; i++)
        {
            int v = nums[i];
            if (!dp.count(v))
                dp[v] = vi(k + 1);
            auto &tmp = dp[v];
            for (int j = 0; j <= k; j++)
            {
                ++tmp[j];
                if (j > 0)
                    tmp[j] = max(tmp[j], zd[j - 1] + 1);
            }
            for (int j = 0; j <= k; ++j)
                zd[j] = max(zd[j], tmp[j]);
        }
        return zd[k];
    }
};

int main()
{
    io;
    return 0;
}
