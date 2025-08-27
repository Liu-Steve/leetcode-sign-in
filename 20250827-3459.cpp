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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

constexpr long long MOD = 1000000007LL;

class Solution
{
    static constexpr int DIRS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

public:
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector<array<array<int, 2>, 4>>(n));
        auto dfs = [&](auto &&dfs, int i, int j, int k, bool can_turn, int target) -> int
        {
            i += DIRS[k][0];
            j += DIRS[k][1];
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target)
                return 0;
            int &res = memo[i][j][k][can_turn];
            if (res)
                return res;
            res = dfs(dfs, i, j, k, can_turn, 2 - target) + 1;
            if (can_turn)
                res = max(res, dfs(dfs, i, j, (k + 1) % 4, false, 2 - target) + 1);
            return res;
        };
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    for (int k = 0; k < 4; k++)
                        ans = max(ans, dfs(dfs, i, j, k, true, 2) + 1);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
