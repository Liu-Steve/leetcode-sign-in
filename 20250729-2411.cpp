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
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        const int len = 31;
        vector<vector<int>> idx(len);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < len; ++j)
                if (nums[i] & (1 << j))
                    idx[j].push_back(i);
        for (int j = 0; j < len; ++j)
            idx[j].push_back(n);
        vector<int> ans(n);
        vector<int> p(len);
        for (int i = 0; i < n; ++i)
        {
            int max_l = 1;
            for (int j = 0; j < len; ++j)
            {
                if (idx[j][p[j]] < i)
                    p[j]++;
                if (p[j] >= idx[j].size() - 1)
                    continue;
                max_l = max(max_l, idx[j][p[j]] - i + 1);
            }
            ans[i] = max_l;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
