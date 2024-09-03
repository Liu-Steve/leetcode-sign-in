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
    long long maxStrength(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] <= 0)
                break;
            ans *= nums[i];
        }
        bool sta = false;
        for (int i = 1; i < n; i += 2)
        {
            if (nums[i] >= 0)
                break;
            sta = true;
            ans *= nums[i - 1] * nums[i];
        }
        if (nums[n - 1] <= 0 && !sta)
            return nums[n - 1];
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
