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
    int superEggDrop(int k, int n)
    {
        vector<int> dp1(n + 1);
        for (int i = 1; i <= n; ++i)
            dp1[i] = i;
        vector<int> dp2(n + 1);
        for (int ki = 2; ki <= k; ++ki)
        {
            for (int ni = 1; ni <= n; ++ni)
            {
                dp2[ni] = dp2[ni - 1] + 1;
                int l = 1;
                int r = ni;
                while (r - l > 1)
                {
                    int m = (l + r) / 2;
                    dp2[ni] = min(dp2[ni], max(dp1[m - 1], dp2[ni - m]) + 1);
                    if (dp1[m - 1] > dp2[ni - m])
                        r = m;
                    else
                        l = m;
                }
            }
            swap(dp1, dp2);
        }
        return dp1[n];
    }
};

int main()
{
    io;
    return 0;
}
