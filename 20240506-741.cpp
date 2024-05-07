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
        vector<vv> mem(n * 2 - 1, vv(n, vi(n, -1)));
        function<int(int, int, int)> dfs = [&](int t, int j, int k)
        {
            if (j < 0 || k < 0 || t < j || t < k || grid[t - j][j] < 0 || grid[t - k][k] < 0)
                return INT_MIN;
            if (t == 0)
                return grid[0][0];
            int &res = mem[t][j][k];
            if (res != -1)
                return res;
            res = max({dfs(t - 1, j, k),
                       dfs(t - 1, j, k - 1),
                       dfs(t - 1, j - 1, k),
                       dfs(t - 1, j - 1, k - 1)}) +
                  grid[t - j][j] + (k != j ? grid[t - k][k] : 0);
            return res;
        };
        return max(0, dfs(n * 2 - 2, n - 1, n - 1));
    }
};

int main()
{
    io;
    return 0;
}
