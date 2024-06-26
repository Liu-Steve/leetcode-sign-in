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
    int specialPerm(vi &nums)
    {
        int n = nums.size();
        vv nxt(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
                {
                    nxt[i].push_back(j);
                    nxt[j].push_back(i);
                }
        vv dp(1 << n, vi(n, -1));
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = 1;
        function<int(int, int)> dfs = [&](int msk, int i) -> int
        {
            if (dp[msk][i] != -1)
                return dp[msk][i];
            ll cnt = 0;
            for (int j : nxt[i])
                if ((msk & (1 << j)) != 0)
                    cnt += dfs(msk ^ (1 << i), j);
            cnt %= MOD;
            dp[msk][i] = cnt;
            return cnt;
        };
        ll ans = 0;
        for (int i = 0; i < n; ++i)
            ans += dfs((1 << n) - 1, i);
        ans %= MOD;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
