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

class Solution
{
public:
    int countWays(vv &ranges)
    {
        set<pr> s;
        for (auto &r : ranges)
        {
            auto it1 = s.lower_bound(pr(r[0], -1));
            auto it2 = s.lower_bound(pr(r[1] + 1, -1));
            if (it1 != s.begin())
            {
                it1--;
                if ((*it1).second < r[0])
                    it1++;
            }
            if (it1 == it2)
            {
                s.emplace(r[0], r[1]);
                continue;
            }
            it2--;
            int ll = min(r[0], (*it1).first);
            int rr = max(r[1], (*it2).second);
            it2++;
            s.erase(it1, it2);
            s.emplace(ll, rr);
        }
        return qpow(2, s.size());
    }
};

int main()
{
    io;
    return 0;
}
