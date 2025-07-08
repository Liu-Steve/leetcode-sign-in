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
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        sort(events.begin(), events.end(), [&](vector<int> &e1, vector<int> &e2)
             { return e1[1] < e2[1]; });
        vector<int> idx(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int target = events[i - 1][0];
            if (i == 1 || events[i - 2][1] < target)
            {
                idx[i] = i - 1;
                continue;
            }
            int l = 0;
            int r = i - 1;
            while (l + 1 < r)
            {
                int m = (l + r) / 2;
                if (events[m - 1][1] < target)
                    l = m;
                else
                    r = m;
            }
            idx[i] = l;
        }
        vector<int> dp1(n + 1);
        vector<int> dp2(n + 1);
        while (k--)
        {
            for (int i = 1; i <= n; ++i)
                dp2[i] = max(dp2[i - 1], dp1[idx[i]] + events[i - 1][2]);
            swap(dp1, dp2);
        }
        return dp1.back();
    }
};

int main()
{
    io;
    return 0;
}
