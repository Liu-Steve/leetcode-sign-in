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
    void mul(long long a[4][4], long long b[4][4])
    {
        long long c[4][4];
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                c[i][j] = 0;
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                for (long long k = 0; k < 4; k++)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                a[i][j] = c[i][j];
    }

    long long pow(long long a[4][4], long long n)
    {
        long long c[4][4];
        for (long long i = 0; i < 4; ++i)
            for (long long j = 0; j < 4; ++j)
                c[i][j] = (i == j);
        while (n)
        {
            if (n & 1)
                mul(c, a);
            mul(a, a);
            n >>= 1;
        }
        return c[3][3];
    }

public:
    int numTilings(int n)
    {
        long long a[4][4] = {
            {0, 0, 0, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
            {1, 1, 1, 1}};
        return pow(a, n);
    }
};

int main()
{
    io;
    return 0;
}
