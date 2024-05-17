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
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> vp;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i)
            vp.emplace_back(difficulty[i], profit[i]);
        sort(vp.begin(), vp.end());
        vector<pair<int, int>> w;
        w.emplace_back(0, 0);
        for (auto [d, p] : vp)
        {
            auto &[ld, lp] = w.back();
            if (d == ld)
            {
                lp = p;
                continue;
            }
            if (p <= lp)
                continue;
            w.emplace_back(d, p);
        }
        int ans = 0;
        for (int d : worker)
        {
            auto it = lower_bound(w.begin(), w.end(), pair<int, int>{d, INT32_MAX});
            it--;
            ans += it->second;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
