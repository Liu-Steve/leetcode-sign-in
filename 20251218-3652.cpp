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
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += prices[i] * strategy[i];
        long long origin = ans;
        long long earn = 0;
        for (int i = 0; i < k / 2; ++i)
            earn += prices[i] * -strategy[i];
        for (int i = k / 2; i < k; ++i)
            earn += prices[i] * (1 - strategy[i]);
        ans = max(origin + earn, ans);
        for (int i = k; i < n; ++i)
        {
            earn += prices[i] * (1 - strategy[i]);
            earn += -prices[i - k / 2];
            earn += prices[i - k] * strategy[i - k];
            ans = max(origin + earn, ans);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
