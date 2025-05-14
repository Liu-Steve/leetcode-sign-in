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

const long long MOD = 1000000007LL;

class Solution
{
private:
    vector<vector<int>> multi(vector<vector<int>> &m1, vector<vector<int>> &m2)
    {
        const int n = 26;
        vector ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i][j] = (ans[i][j] + (long long)m1[i][k] * m2[k][j]) % MOD;
        return ans;
    }

    vector<vector<int>> power(vector<vector<int>> &m, int t)
    {
        const int n = 26;
        vector ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            ans[i][i] = 1;
        vector p(m);
        while (t)
        {
            if (t & 1)
                ans = multi(ans, p);
            t >>= 1;
            p = multi(p, p);
        }
        return ans;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        const int n = 26;
        vector m(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                int mod = (j - i + n) % n;
                m[i][j] = (mod > 0 && mod <= nums[i]);
            }
        m = power(m, t);
        vector<int> cnt(n);
        for (char ch : s)
            cnt[ch - 'a']++;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans = (ans + (long long)cnt[i] * m[i][j]) % MOD;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
