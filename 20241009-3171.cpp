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
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = INT32_MAX;
        vector<int> cnt(32);
        auto get_num = [&]() -> int
        {
            int sum = 0;
            for (int i = 0; i < 32; ++i)
                if (cnt[i])
                    sum |= (1 << i);
            return sum;
        };
        for (; r < n; ++r)
        {
            for (int i = 0; i < 32; ++i)
                if (nums[r] & (1 << i))
                    cnt[i]++;
            int num = get_num();
            ans = min(ans, abs(num - k));
            while (num > k && r - l > 0)
            {
                for (int i = 0; i < 32; ++i)
                    if (nums[l] & (1 << i))
                        cnt[i]--;
                l++;
                num = get_num();
                ans = min(ans, abs(num - k));
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
