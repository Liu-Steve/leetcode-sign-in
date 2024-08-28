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
    int minimumSubstringsInPartition(string s)
    {
        int n = s.size();
        vector<vector<int>> pre(n + 1, vector<int>(26));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 26; ++j)
                pre[i + 1][j] = pre[i][j];
            pre[i + 1][s[i] - 'a']++;
        }
        auto valid = [&](int i, int j) -> bool
        {
            int cnt = -1;
            for (int k = 0; k < 26; ++k)
            {
                int num = pre[j][k] - pre[i][k];
                if (num == 0 || cnt == num)
                    continue;
                else if (cnt == -1)
                    cnt = num;
                else
                    return false;
            }
            return true;
        };
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; ++j)
            for (int i = 0; i < j; ++i)
                if (valid(i, j))
                    dp[j] = min(dp[j], dp[i] + 1);
        return dp[n];
    }
};

int main()
{
    io;
    return 0;
}
