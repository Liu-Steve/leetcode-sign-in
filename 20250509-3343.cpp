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

long long power(long long x, int n)
{
    long long res = 1;
    for (; n; n /= 2)
    {
        if (n % 2)
            res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        const int MX = 41;
        vector<long long> F(MX);
        vector<long long> INV_F(MX);
        F[0] = 1;
        for (int i = 1; i < MX; i++)
            F[i] = F[i - 1] * i % MOD;
        INV_F[MX - 1] = power(F[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--)
            INV_F[i - 1] = INV_F[i] * i % MOD;

        vector cnt(10, 0);
        int total = 0;
        for (char c : num)
        {
            cnt[c - '0']++;
            total += c - '0';
        }
        if (total % 2)
            return 0;
        partial_sum(cnt.begin(), cnt.end(), cnt.begin());

        int n = num.size();
        int n1 = n / 2;
        vector<vector<vector<int>>> memo(10, vector(n1 + 1, vector<int>(total / 2 + 1, -1)));
        auto dfs = [&](auto &dfs, int i, int left1, int left_s) -> int
        {
            if (i < 0)
                return left_s == 0;
            int &res = memo[i][left1][left_s];
            if (res != -1)
                return res;
            res = 0;
            int c = cnt[i] - (i ? cnt[i - 1] : 0);
            int left2 = cnt[i] - left1;
            for (int k = max(c - left2, 0); k <= min(c, left1) && k * i <= left_s; k++)
            {
                int r = dfs(dfs, i - 1, left1 - k, left_s - k * i);
                res = (res + r * INV_F[k] % MOD * INV_F[c - k]) % MOD;
            }
            return res;
        };
        return F[n1] * F[n - n1] % MOD * dfs(dfs, 9, n1, total / 2) % MOD;
    }
};

int main()
{
    io;
    return 0;
}
