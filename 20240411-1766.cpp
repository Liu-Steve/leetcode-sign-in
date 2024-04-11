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
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> pri(51);
        for (int i = 1; i <= 50; ++i)
            for (int j = 1; j <= 50; ++j)
                if (gcd(i, j) == 1)
                    pri[i].push_back(j);
        vector<vector<int>> nxt(n);
        for (auto &e : edges)
        {
            nxt[e[0]].push_back(e[1]);
            nxt[e[1]].push_back(e[0]);
        }

        vector<int> depth(n, -1);
        vector<int> ans(n, -1);
        vector<stack<int>> fa(51);
        function<void(int, int)> dfs = [&](int root, int d)
        {
            if (depth[root] != -1)
                return;
            int d_max = -1;
            for (int val : pri[nums[root]])
            {
                if (fa[val].empty())
                    continue;
                int node = fa[val].top();
                if (depth[node] <= d_max)
                    continue;
                d_max = depth[node];
                ans[root] = node;
            }
            depth[root] = d;
            fa[nums[root]].push(root);
            for (int ch : nxt[root])
                dfs(ch, d + 1);
            fa[nums[root]].pop();
        };
        dfs(0, 0);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
