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
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int ans = 0;
        int i = k + 1;
        int j = k + 1;
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        int n = nums.size();
        while (i != 0 || j != n - 1)
        {
            int lmt = max(nums[i], nums[j]);
            while (nums[i] >= lmt)
                i--;
            while (nums[j] >= lmt)
                j++;
            ans = max(ans, lmt * (j - i - 1));
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
