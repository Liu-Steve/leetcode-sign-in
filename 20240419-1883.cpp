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
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        auto upper = [=](ll num)
        {
            return (num / speed + (num % speed != 0)) * speed;
        };
        int n = dist.size();
        ll d = (ll)speed * hoursBefore;
        vvl dp(n, vl(n + 1));
        for (int i = 1; i <= n; ++i)
            dp[0][i] = upper(dp[0][i - 1]) + dist[i - 1];
        if (dp[0][n] <= d)
            return 0;
        for (int k = 1; k < n; ++k)
        {
            for (int i = 1; i <= n; ++i)
                dp[k][i] = min(upper(dp[k][i - 1]), dp[k - 1][i - 1]) + dist[i - 1];
            if (dp[k][n] <= d)
                return k;
        }
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
