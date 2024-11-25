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
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        vector<vector<int>> pos;
        for (int i = 0; i < k; ++i)
            for (int num : nums[i])
                pos.emplace_back(vector<int>{num, i});
        sort(pos.begin(), pos.end());
        vector<int> ans{-900000, -100000};
        auto update = [&](int x, int y) -> void
        {
            if (y - x >= ans[1] - ans[0])
                return;
            ans[0] = x;
            ans[1] = y;
        };
        vector<int> cnt(k);
        int l = 0;
        int r = 0;
        int mark = k;
        while (mark)
        {
            int g = pos[r][1];
            if (!cnt[g])
                mark--;
            cnt[g]++;
            r++;
        }
        update(pos[l][0], pos[r - 1][0]);
        while (r <= pos.size())
        {
            cnt[pos[l][1]]--;
            l++;
            if (cnt[pos[l - 1][1]])
            {
                update(pos[l][0], pos[r - 1][0]);
                continue;
            }
            while (r < pos.size() && !cnt[pos[l - 1][1]])
            {
                cnt[pos[r][1]]++;
                r++;
            }
            if (!cnt[pos[l - 1][1]])
                break;
            update(pos[l][0], pos[r - 1][0]);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
