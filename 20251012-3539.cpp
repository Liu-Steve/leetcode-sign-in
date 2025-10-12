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

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    long long quickmul(long long x, long long y, long long mod)
    {
        long long res = 1, cur = x % mod;
        while (y)
        {
            if (y & 1)
                res = res * cur % mod;
            y >>= 1;
            cur = cur * cur % mod;
        }
        return res;
    };

    int magicalSum(int m, int k, vector<int> &nums)
    {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<long long> fac(m + 1, 1);
        for (int i = 1; i <= m; i++)
            fac[i] = fac[i - 1] * i % mod;
        vector<long long> ifac(m + 1, 1);
        for (int i = 2; i <= m; i++)
            ifac[i] = quickmul(i, mod - 2, mod);
        for (int i = 2; i <= m; i++)
            ifac[i] = ifac[i - 1] * ifac[i] % mod;
        vector numsPower(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
        vector f(n, vector(m + 1, vector(m * 2 + 1, vector<long long>(k + 1, 0))));
        for (int j = 0; j <= m; j++)
            f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
        for (int i = 0; i + 1 < n; i++)
            for (int j = 0; j <= m; j++)
                for (int p = 0; p <= m * 2; p++)
                    for (int q = 0; q <= k; q++)
                    {
                        int q2 = p % 2 + q;
                        if (q2 > k)
                            break;
                        for (int r = 0; r + j <= m; r++)
                        {
                            int p2 = p / 2 + r;
                            f[i + 1][j + r][p2][q2] += f[i][j][p][q] * numsPower[i + 1][r] % mod * ifac[r] % mod;
                            f[i + 1][j + r][p2][q2] %= mod;
                        }
                    }
        long long res = 0;
        for (int p = 0; p <= m * 2; p++)
            for (int q = 0; q <= k; q++)
                if (__builtin_popcount(p) + q == k)
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod) % mod;
        return res;
    }
};

int main()
{
    io;
    return 0;
}
