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
    int cherryPickup(vv &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vv> mem(n, vv(m, vi(m, -1)));
        function<int(int, int, int)> dfs = [&](int t, int j, int k)
        {
            if (j < 0 || k < 0 || j >= m || k >= m)
                return INT_MIN;
            if (t == n - 1)
                return grid[t][j] + (k != j ? grid[t][k] : 0);
            int &res = mem[t][j][k];
            if (res != -1)
                return res;
            res = max({dfs(t + 1, j - 1, k - 1),
                       dfs(t + 1, j - 1, k),
                       dfs(t + 1, j - 1, k + 1),
                       dfs(t + 1, j, k - 1),
                       dfs(t + 1, j, k),
                       dfs(t + 1, j, k + 1),
                       dfs(t + 1, j + 1, k - 1),
                       dfs(t + 1, j + 1, k),
                       dfs(t + 1, j + 1, k + 1)}) +
                  grid[t][j] + (k != j ? grid[t][k] : 0);
            return res;
        };
        return dfs(0, 0, m - 1);
    }
};

int main()
{
    io;
    return 0;
}
