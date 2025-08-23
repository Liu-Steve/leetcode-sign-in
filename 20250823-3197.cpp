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
private:
    auto rotate(const auto &a)
    {
        int m = a.size();
        int n = a[0].size();
        vector ans(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans[j][i] = a[i][j];
        return ans;
    }

    int minimum(const auto &a, int t, int b, int l, int r)
    {
        int min_i = a.size();
        int max_i = 0;
        int min_j = a[0].size();
        int max_j = 0;
        for (int i = t; i < b; ++i)
            for (int j = l; j < r; ++j)
                if (a[i][j])
                {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
        if (min_i > max_i)
            return INT32_MAX / 3;
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }

    int solve(const auto &a)
    {
        int m = a.size();
        int n = a[0].size();
        int ans = m * n;
        for (int i = 1; i < m; ++i)
            for (int j = i + 1; j < m; ++j)
            {
                int s1 = minimum(a, 0, i, 0, n);
                int s2 = minimum(a, i, j, 0, n);
                int s3 = minimum(a, j, m, 0, n);
                ans = min(ans, s1 + s2 + s3);
            }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                int s1 = minimum(a, 0, i, 0, n);
                int s2 = minimum(a, i, m, 0, j);
                int s3 = minimum(a, i, m, j, n);
                ans = min(ans, s1 + s2 + s3);
                s1 = minimum(a, i, m, 0, n);
                s2 = minimum(a, 0, i, 0, j);
                s3 = minimum(a, 0, i, j, n);
                ans = min(ans, s1 + s2 + s3);
            }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>> &grid)
    {
        auto r_grid = rotate(grid);
        return min(solve(grid), solve(r_grid));
    }
};

int main()
{
    io;
    return 0;
}
