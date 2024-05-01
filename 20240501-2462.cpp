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
    ll totalCost(vi &costs, int k, int candidates)
    {
        int n = costs.size();
        priority_queue<pr, vp, greater<pr>> q;
        int l = candidates - 1;
        int r = n - candidates;
        if (l + 1 < r)
        {
            for (int i = 0; i <= l; ++i)
                q.emplace(costs[i], i);
            for (int i = n - 1; i >= r; --i)
                q.emplace(costs[i], i);
        }
        else
            for (int i = 0; i < n; ++i)
                q.emplace(costs[i], i);
        ll ans = 0;
        while (k--)
        {
            auto [cost, id] = q.top();
            q.pop();
            ans += cost;
            if (l + 1 < r)
            {
                if (id <= l)
                {
                    ++l;
                    q.emplace(costs[l], l);
                }
                else
                {
                    --r;
                    q.emplace(costs[r], r);
                }
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
