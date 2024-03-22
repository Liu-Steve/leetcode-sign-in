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
    int minimumVisitedCells(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), mn;
        vector<vector<pair<int, int>>> col_stacks(n);
        vector<pair<int, int>> row_st;
        for (int i = m - 1; i >= 0; i--)
        {
            row_st.clear();
            for (int j = n - 1; j >= 0; j--)
            {
                int g = grid[i][j];
                auto &col_st = col_stacks[j];
                mn = i < m - 1 || j < n - 1 ? INT_MAX : 1;
                if (g)
                {
                    auto it = lower_bound(row_st.begin(), row_st.end(), j + g, [](const auto &a, const int b)
                                          { return a.second > b; });
                    if (it < row_st.end())
                        mn = it->first + 1;
                    it = lower_bound(col_st.begin(), col_st.end(), i + g, [](const auto &a, const int b)
                                     { return a.second > b; });
                    if (it < col_st.end())
                        mn = min(mn, it->first + 1);
                }
                if (mn < INT_MAX)
                {
                    while (!row_st.empty() && mn <= row_st.back().first)
                        row_st.pop_back();
                    row_st.emplace_back(mn, j);
                    while (!col_st.empty() && mn <= col_st.back().first)
                        col_st.pop_back();
                    col_st.emplace_back(mn, i);
                }
            }
        }
        return mn < INT_MAX ? mn : -1;
    }
};

int main()
{
    io;
    return 0;
}
