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
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

ll frac_mod(ll a, ll b)
{
    ll ans = a % MOD;
    ans *= qpow(b, MOD - 2);
    ans = ans % MOD;
    return ans;
}

class Solution
{
public:
    int minNonZeroProduct(int p)
    {
        if (p == 1)
            return 1;
        ll ep = ((1ll << p) - 2) % MOD;
        ll k = ((1ll << p) - 2) / 2;
        ll ans = qpow(ep, k) * (ep + 1) % MOD;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
