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
    int minimumValueSum(vi &nums, vi &andValues)
    {
        const int INF = INT_MAX / 2;
        int n = nums.size();
        int m = andValues.size();
        memory memo;
        auto dfs = [&](auto &&dfs, int i, int j, int v) -> int
        {
            if (n - i < m - j)
                return INF;
            if (j == m)
                return i == n ? 0 : INF;
            v &= nums[i];
            ll msk = (ll)i << 36 | (ll)j << 32 | v;
            if (memo.count(msk))
                return memo[msk];
            int res = dfs(dfs, i + 1, j, v);
            if (v == andValues[j])
                res = min(res, dfs(dfs, i + 1, j + 1, -1) + nums[i]);
            return memo[msk] = res;
        };
        int ans = dfs(dfs, 0, 0, -1);
        return ans < INF ? ans : -1;
    }
};

int main()
{
    io;
    return 0;
}
