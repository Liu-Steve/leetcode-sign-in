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

long long qpow(long long a, long long b, long long mod)
{
    long long ans = 1 % mod;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans % mod;
}

long long sum_e(long long k)
{
    long long res = 0, n = 0, cnt1 = 0, sum_i = 0;
    for (long long i = __lg(k + 1); i >= 0; i--)
    {
        long long c = (cnt1 << i) + (i << i >> 1);
        if (c <= k)
        {
            k -= c;
            res += (sum_i << i) + ((i * (i - 1) / 2) << i >> 1);
            sum_i += i;
            cnt1++;
            n |= 1LL << i;
        }
    }
    while (k--)
    {
        res += __builtin_ctzll(n);
        n &= n - 1;
    }
    return res;
}

class Solution
{
public:
    vector<int> findProductsOfElements(vector<vector<long long>> &queries)
    {
        vector<int> ans;
        for (auto &q : queries)
        {
            auto er = sum_e(q[1] + 1);
            auto el = sum_e(q[0]);
            ans.push_back(qpow(2, er - el, q[2]));
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
