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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int numberOfPermutations(int n, vector<vector<int>> &requirements)
    {
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto &p : requirements)
            req[p[0]] = p[1];
        if (req[0])
            return 0;
        int m = *max_element(req.begin(), req.end());
        vector<int> f(m + 1);
        f[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int mx = req[i] < 0 ? m : req[i];
            if (int r = req[i - 1]; r >= 0)
            {
                fill(f.begin(), f.begin() + r, 0);
                fill(f.begin() + r + 1, f.begin() + min(i + r, mx) + 1, f[r]);
                fill(f.begin() + min(i + r, mx) + 1, f.end(), 0);
            }
            else
            {
                for (int j = 1; j <= mx; j++)
                    f[j] = (f[j] + f[j - 1]) % MOD;
                for (int j = mx; j > i; j--)
                    f[j] = (f[j] - f[j - i - 1] + MOD) % MOD;
            }
        }
        return f[req[n - 1]];
    }
};

int main()
{
    io;
    return 0;
}
