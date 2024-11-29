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

//(a^b)%MOD
long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

//(a/b)%MOD
long long frac_mod(long long a, long long b)
{
    long long ans = a % MOD;
    ans *= qpow(b, MOD - 2);
    ans = ans % MOD;
    return ans;
}

class Solution
{
public:
    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        int m = nums[n - 1];
        for (int i = 0; i < n - 1; ++i)
            m -= max(nums[i + 1] - nums[i], 0);
        if (m < 0)
            return 0;
        long long ans = 1;
        for (int i = 0; i < n; ++i)
            ans = ans * (m + n - i) % MOD;
        for (int i = 0; i < n; ++i)
            ans = frac_mod(ans, i + 1);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
