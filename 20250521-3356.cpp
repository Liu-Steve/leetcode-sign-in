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
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (int i = 0; i < k; ++i)
        {
            auto &q = queries[i];
            diff[q[0]] += q[2];
            diff[q[1] + 1] -= q[2];
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += diff[i];
            if (nums[i] > sum)
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int l = 0;
        int r = queries.size();
        if (isZeroArray(nums, queries, l))
            return 0;
        if (!isZeroArray(nums, queries, r))
            return -1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (isZeroArray(nums, queries, mid))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};

int main()
{
    io;
    return 0;
}
