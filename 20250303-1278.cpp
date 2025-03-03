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
    int palindromePartition(string s, int k)
    {
        int n = s.size();
        vector modify(n, vector<int>(n));
        for (int len = 1; len < n; ++len)
            for (int l = 0; l + len < n; ++l)
                modify[l][l + len] = modify[l + 1][l + len - 1] + (s[l] != s[l + len]);
        vector dp1(n, 0);
        vector dp2(n, 0);
        for (int i = 0; i < n; ++i)
            dp1[i] = modify[0][i];
        for (int i = 1; i < k; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                dp2[j] = INT32_MAX;
                for (int k = i - 1; k < j; ++k)
                    dp2[j] = min(dp2[j], dp1[k] + modify[k + 1][j]);
            }
            swap(dp1, dp2);
        }
        return dp1.back();
    }
};

int main()
{
    io;
    return 0;
}
