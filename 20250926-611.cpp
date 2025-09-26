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
    int triangleNumber(vector<int> &nums)
    {
        vector<int> cnt(1001), pre(1001);
        for (int num : nums)
            cnt[num]++;
        for (int i = 1; i <= 1000; ++i)
            pre[i] = cnt[i] + pre[i - 1];
        int ans = 0;
        for (int i = 1; i <= 1000; ++i)
        {
            ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            ans += cnt[i] * (cnt[i] - 1) / 2 * (pre[min(1000, i * 2 - 1)] - pre[i]);
            for (int j = i + 1; j <= 1000; ++j)
            {
                ans += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                int range = pre[min(1000, i + j - 1)] - pre[j];
                ans += cnt[i] * cnt[j] * range;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
