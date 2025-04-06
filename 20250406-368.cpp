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
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n);
        vector<int> ptr(n, -1);
        int ans_idx = -1;
        int ans_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int con_idx = -1;
            int con_cnt = 0;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] != 0 || dp[j] <= con_cnt)
                    continue;
                con_idx = j;
                con_cnt = dp[j];
            }
            ptr[i] = con_idx;
            dp[i] = con_cnt + 1;
            if (dp[i] <= ans_cnt)
                continue;
            ans_idx = i;
            ans_cnt = dp[i];
        }
        vector<int> ans;
        while (ans_idx != -1)
        {
            ans.push_back(nums[ans_idx]);
            ans_idx = ptr[ans_idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
