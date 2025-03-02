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
    int minCut(string s)
    {
        int n = s.size();
        vector valid_mem(n, vector<int>(n, -1));
        auto valid = [&](auto &&valid, int l, int r) -> bool
        {
            if (l >= r)
                return true;
            int &ans = valid_mem[l][r];
            if (ans != -1)
                return ans;
            return ans = (s[l] == s[r] && valid(valid, l + 1, r - 1));
        };
        vector<int> dfs_mem(n, INT32_MAX);
        auto dfs = [&](auto &&dfs, int r) -> int
        {
            if (valid(valid, 0, r))
                return 0;
            int &ans = dfs_mem[r];
            if (ans != INT32_MAX)
                return ans;
            for (int l = 1; l <= r; ++l)
                if (valid(valid, l, r))
                    ans = min(ans, dfs(dfs, l - 1) + 1);
            return ans;
        };
        return dfs(dfs, n - 1);
    }
};

int main()
{
    io;
    return 0;
}
