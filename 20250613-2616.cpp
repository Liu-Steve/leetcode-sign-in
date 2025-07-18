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
    int minimizeMax(vector<int> &nums, int p)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto valid = [&](int limit)
        {
            int cnt = 1;
            int ans = 0;
            for (int i = 1; i < n; ++i)
            {
                if (nums[i] - nums[i - 1] <= limit)
                {
                    cnt++;
                    continue;
                }
                ans += cnt / 2;
                cnt = 1;
            }
            ans += cnt / 2;
            return ans >= p;
        };
        if (valid(0))
            return 0;
        int l = 0;
        int r = INT32_MAX / 2;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (valid(m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};

int main()
{
    io;
    return 0;
}
