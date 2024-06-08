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
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        vector<int> ops = {nums[0] + nums[1], nums[0] + nums[n - 1], nums[n - 2] + nums[n - 1]};
        for (int op : ops)
        {
            vector<vector<int>> dp(n + 1, vector<int>(n + 1));
            for (int l = n - 2; l >= 0; --l)
                for (int r = l + 2; r <= n; ++r)
                {
                    if (op == nums[l] + nums[l + 1])
                        dp[l][r] = max(dp[l][r], dp[l + 2][r] + 1);
                    if (op == nums[l] + nums[r - 1])
                        dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 1);
                    if (op == nums[r - 2] + nums[r - 1])
                        dp[l][r] = max(dp[l][r], dp[l][r - 2] + 1);
                }
            ans = max(ans, dp[0][n]);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
