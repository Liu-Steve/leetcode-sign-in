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
    int maxScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> precol(n, INT_MIN);
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i)
        {
            int prerow = INT_MIN;
            for (int j = 0; j < n; ++j)
            {
                int f = INT_MIN;
                if (i > 0)
                    f = max(f, grid[i][j] + precol[j]);
                if (j > 0)
                    f = max(f, grid[i][j] + prerow);
                ans = max(ans, f);
                precol[j] = max(precol[j], max(f, 0) - grid[i][j]);
                prerow = max(prerow, max(f, 0) - grid[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
