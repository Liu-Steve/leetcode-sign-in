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
public:
    int minIncrements(int n, vector<int> &cost)
    {
        for (int i = 0; i < n / 2; ++i)
        {
            cost[2 * i + 1] += cost[i];
            cost[2 * i + 2] += cost[i];
        }
        int target = *max_element(cost.begin() + n / 2, cost.end());
        vector<int> add(cost.begin() + n / 2, cost.end());
        int len = n / 2 + 1;
        for (int i = 0; i < len; ++i)
            add[i] = target - add[i];
        int ans = 0;
        for (int i = 1; i < len; i *= 2)
        {
            for (int j = 0; j < len; j += 2 * i)
            {
                int common = min(add[j], add[j + i]);
                ans += add[j] + add[j + i] - 2 * common;
                add[j] = common;
            }
        }
        ans += add[0];
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
