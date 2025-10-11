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
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector pac(m, vector(n, 0));
        vector atl(m, vector(n, 0));
        queue<pair<int, int>> q;
        vector<int> b{0, 1, 0, -1, 0};
        auto bfs = [&](vector<vector<int>> &mp) -> void
        {
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + b[i];
                    int ny = y + b[i + 1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || mp[nx][ny] == 1 || heights[nx][ny] < heights[x][y])
                        continue;
                    q.emplace(nx, ny);
                    mp[nx][ny] = 1;
                }
            }
        };
        for (int i = 0; i < m; ++i)
        {
            pac[i][0] = 1;
            q.emplace(i, 0);
        }
        for (int j = 1; j < n; ++j)
        {
            pac[0][j] = 1;
            q.emplace(0, j);
        }
        bfs(pac);
        for (int i = 0; i < m; ++i)
        {
            atl[i][n - 1] = 1;
            q.emplace(i, n - 1);
        }
        for (int j = 0; j < n - 1; ++j)
        {
            atl[m - 1][j] = 1;
            q.emplace(m - 1, j);
        }
        bfs(atl);
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j])
                    ans.push_back(vector<int>{i, j});
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
