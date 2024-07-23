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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    int sumOfPowers(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        vector<vector<memory>> d(n, vector<memory>(k + 1));
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            d[i][1][0x3f3f3f3f] = 1;
            for (int j = 0; j < i; j++)
            {
                int diff = abs(nums[i] - nums[j]);
                for (int p = 2; p <= k; p++)
                    for (auto &[v, cnt] : d[j][p - 1])
                        d[i][p][min(diff, v)] = (d[i][p][min(diff, v)] + cnt) % MOD;
            }
            for (auto &[v, cnt] : d[i][k])
                res = (res + 1ll * v * cnt % MOD) % MOD;
        }
        return res;
    }
};

int main()
{
    io;
    return 0;
}
