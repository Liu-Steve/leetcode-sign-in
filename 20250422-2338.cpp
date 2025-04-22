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
#define MAX_N 10000
#define MAX_E 13

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
    int idealArrays(int n, int maxValue)
    {
        vector EXP(MAX_N + 1, vector<int>());
        vector C(MAX_N + MAX_E, vector<int>(MAX_E + 1));
        for (int x = 2; x <= MAX_N; ++x)
        {
            int t = x;
            for (int i = 2; i * i <= t; ++i)
            {
                int e = 0;
                for (; t % i == 0; t /= i)
                    ++e;
                if (e)
                    EXP[x].push_back(e);
            }
            if (t > 1)
                EXP[x].push_back(1);
        }
        for (int i = 0; i < MAX_N + MAX_E; ++i)
        {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_E); ++j)
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
        long long ans = 0;
        for (int x = 1; x <= maxValue; ++x)
        {
            long long res = 1;
            for (int e : EXP[x])
                res = res * C[n + e - 1][e] % MOD;
            ans += res;
        }
        return ans % MOD;
    }
};

int main()
{
    io;
    return 0;
}
