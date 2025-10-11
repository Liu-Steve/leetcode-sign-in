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

class DSet
{
private:
    int *fa;
    int n;
    int findFa(int node)
    {
        while (fa[node] >= 0)
        {
            node = fa[node];
        }
        return node;
    }

public:
    DSet(int n)
    {
        fa = new int[n];
        for (int i = 0; i < n; ++i)
            fa[i] = -1;
    }

    bool find(int n1, int n2)
    {
        return findFa(n1) == findFa(n2);
    }

    void add(int n1, int n2)
    {
        int fa1 = findFa(n1);
        int fa2 = findFa(n2);
        if (fa1 == fa2)
            return;
        if (fa[fa1] > fa[fa2])
        {
            fa[fa2] += fa[fa1];
            fa[fa1] = fa2;
        }
        else
        {
            fa[fa1] += fa[fa2];
            fa[fa2] = fa1;
        }
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DSet s(n * n);
        vector<pair<int, int>> p(n * n);
        vector<int> b{0, 1, 0, -1, 0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                p[grid[i][j]] = {i, j};
        for (int t = 0; t < n * n; ++t)
        {
            auto [x, y] = p[t];
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + b[i];
                int ny = y + b[i + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] > t)
                    continue;
                s.add(t, grid[nx][ny]);
            }
            if (s.find(grid[0][0], grid[n - 1][n - 1]))
                return t;
        }
        return n * n;
    }
};

int main()
{
    io;
    return 0;
}
