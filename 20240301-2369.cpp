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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
private:
    bool dfs(int head, vector<int> &nums)
    {
        if (nums.size() - head == 0)
            return true;
        if (nums.size() - head == 1)
            return false;
        if (nums.size() - head == 2)
            return nums[head] == nums[head + 1];
        if (nums[head] - nums[head + 1] == -1 && nums[head + 1] - nums[head + 2] == -1)
            return dfs(head + 3, nums);
        int cnt = 1;
        for (; cnt + head < nums.size(); ++cnt)
            if (nums[head] != nums[head + cnt])
                break;
        if (cnt == 1)
            return false;
        if (cnt == 2)
            return dfs(head + 2, nums);
        return dfs(head + cnt - 1, nums) || dfs(head + cnt, nums);
    }

public:
    bool validPartition(vector<int> &nums)
    {
        return dfs(0, nums);
    }
};

int main()
{
    io;
    return 0;
}
