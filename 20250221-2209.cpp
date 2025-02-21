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
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        int n = floor.size();
        int wcnt = floor[0] - '0';
        vector<int> pre(n);
        pre[0] = floor[0] - '0';
        for (int i = 1; i < n; ++i)
        {
            wcnt += floor[i] - '0';
            pre[i] = pre[i - 1] + floor[i] - '0';
            if (i >= carpetLen)
                pre[i] -= floor[i - carpetLen] - '0';
        }
        vector<int> dp1(n), dp2(n);
        for (int i = 0; i < numCarpets; ++i)
        {
            dp2[0] = pre[0];
            for (int j = 1; j < n; ++j)
            {
                dp2[j] = max(dp2[j - 1], pre[j] + (j >= carpetLen ? dp1[j - carpetLen] : 0));
            }
            swap(dp1, dp2);
        }
        return wcnt - dp1.back();
    }
};

int main()
{
    io;
    return 0;
}
