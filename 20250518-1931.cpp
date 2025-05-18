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
public:
    int colorTheGrid(int m, int n)
    {
        vector<int> p(m + 1, 1);
        for (int i = 1; i <= m; ++i)
            p[i] = p[i - 1] * 3;
        vector<int> valid;
        for (int i = 0; i < p[m]; ++i)
        {
            bool v = true;
            for (int j = 0; j < m - 1; ++j)
            {
                if ((i / p[j]) % 3 != (i / p[j + 1]) % 3)
                    continue;
                v = false;
                break;
            }
            if (v)
                valid.push_back(i);
        }
        int len = valid.size();
        vector<int> dp1(len, 1), dp2(len);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                dp2[j] = 0;
                for (int k = 0; k < len; ++k)
                {
                    bool v = true;
                    for (int t = 0; t < m; ++t)
                    {
                        if ((valid[j] / p[t]) % 3 != (valid[k] / p[t]) % 3)
                            continue;
                        v = false;
                        break;
                    }
                    if (v)
                        dp2[j] = (dp2[j] + dp1[k]) % MOD;
                }
            }
            swap(dp1, dp2);
        }
        return reduce(dp1.begin(), dp1.end(), 0ll) % MOD;
    }
};

int main()
{
    io;
    return 0;
}
