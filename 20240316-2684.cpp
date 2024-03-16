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
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        auto get = [&](int x, int y, int val)
        {
            if (x >= m || x < 0 || y >= n || y < 0 || val >= grid[x][y])
                return -1;
            return dp[x][y];
        };
        for (int y = n - 1; y >= 0; --y)
            for (int x = 0; x < m; ++x)
                dp[x][y] =
                    max(get(x - 1, y + 1, grid[x][y]), max(get(x, y + 1, grid[x][y]), get(x + 1, y + 1, grid[x][y]))) + 1;
        int ans = 0;
        for (int i = 0; i < m; ++i)
            ans = max(ans, dp[i][0]);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
