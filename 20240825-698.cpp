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
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        if (sum % k != 0)
            return false;
        sum /= k;
        vector<int> stat(k);
        auto dfs = [&](auto &&dfs, int idx) -> bool
        {
            if (idx == n)
                return true;
            for (int i = 0; i < k; ++i)
            {
                if (stat[i] + nums[idx] > sum)
                    continue;
                if (i > 0 && stat[i] == stat[i - 1])
                    continue;
                stat[i] += nums[idx];
                bool ret = dfs(dfs, idx + 1);
                if (ret)
                    return true;
                stat[i] -= nums[idx];
            }
            return false;
        };
        return dfs(dfs, 0);
    }
};

int main()
{
    io;
    return 0;
}
