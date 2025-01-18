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
    int maxValue(vector<int> &nums, int k)
    {
        const int MX = 1 << 7;
        int n = nums.size();
        vector<array<int, MX>> suf(n - k + 1);
        vector<array<int, MX>> f(k + 1);
        f[0][0] = true;
        for (int i = n - 1; i >= k; --i)
        {
            int v = nums[i];
            for (int j = min(k - 1, n - 1 - i); j >= 0; --j)
                for (int x = 0; x < MX; ++x)
                    if (f[j][x])
                        f[j + 1][x | v] = true;
            if (i <= n - k)
                suf[i] = f[k];
        }
        int ans = 0;
        f = vector<array<int, MX>>(k + 1);
        f[0][0] = true;
        for (int i = 0; i < n - k; ++i)
        {
            int v = nums[i];
            for (int j = min(k - 1, i); j >= 0; --j)
                for (int x = 0; x < MX; ++x)
                    if (f[j][x])
                        f[j + 1][x | v] = true;
            if (i < k - 1)
                continue;
            for (int x = 0; x < MX; ++x)
                if (f[k][x])
                    for (int y = 0; y < MX; ++y)
                        if (suf[i + 1][y])
                            ans = max(ans, x ^ y);
            if (ans == MX - 1)
                return ans;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
