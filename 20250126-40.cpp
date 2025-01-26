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
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> cnt(target + 1);
        for (int c : candidates)
        {
            if (c > target)
                continue;
            cnt[c]++;
        }
        vector<vector<int>> ans;
        vector<int> plan;
        auto dfs = [&](auto &&dfs, int i, int sum) -> void
        {
            if (sum == target)
            {
                ans.push_back(plan);
                return;
            }
            if (i > target)
                return;
            dfs(dfs, i + 1, sum);
            for (int j = 0; j < cnt[i]; ++j)
            {
                sum += i;
                plan.push_back(i);
                if (sum > target)
                    break;
                dfs(dfs, i + 1, sum);
            }
            while (!plan.empty() && plan.back() == i)
            {
                plan.pop_back();
                sum -= i;
            }
        };
        dfs(dfs, 1, 0);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
