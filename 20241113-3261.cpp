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
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> l2r(n, n), r2l(n);
        vector<int> cnt(2);
        int l = 0;
        for (int r = 0; r < n; ++r)
        {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k)
            {
                cnt[s[l] - '0']--;
                l2r[l] = r;
                l++;
            }
            r2l[r] = l;
        }
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + i - r2l[i] + 1;
        int m = queries.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; ++i)
        {
            auto &q = queries[i];
            long long p = min(l2r[q[0]], q[1] + 1);
            ans[i] = (p - q[0]) * (p - q[0] + 1) / 2 + prefix[q[1] + 1] - prefix[p];
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
