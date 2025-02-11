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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump)
    {
        int n = grid.size(), m = grid[0].size();
        int catX = 0, catY = 0, mouseX = 0, mouseY = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 'C')
                {
                    catX = i;
                    catY = j;
                    grid[i][j] = '.';
                }
                if (grid[i][j] == 'M')
                {
                    mouseX = i;
                    mouseY = j;
                    grid[i][j] = '.';
                }
            }
        int f[8][8][8][8][128];
        memset(f, -1, sizeof(f));
        vector<int> b{0, 1, 0, -1, 0};
        auto dfs = [&](auto &&dfs, int cx, int cy, int mx, int my, int step, int f[8][8][8][8][128]) -> bool
        {
            if (step >= 128)
                return false;
            int &v = f[cx][cy][mx][my][step];
            if (v != -1)
                return v;
            if ((cx == mx && cy == my) || (grid[cx][cy] == 'F'))
                return v = false;
            if (grid[mx][my] == 'F')
                return v = true;
            if (step & 1)
            {
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j <= catJump; ++j)
                    {
                        int x = cx + j * b[i];
                        int y = cy + j * b[i + 1];
                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
                            break;
                        if (dfs(dfs, x, y, mx, my, step + 1, f) == false)
                            return v = false;
                    }
                return v = true;
            }
            else
            {
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j <= mouseJump; ++j)
                    {
                        int x = mx + j * b[i];
                        int y = my + j * b[i + 1];
                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
                            break;
                        if (dfs(dfs, cx, cy, x, y, step + 1, f) == true)
                            return v = true;
                    }
                return v = false;
            }
        };
        return dfs(dfs, catX, catY, mouseX, mouseY, 0, f);
    }
};

int main()
{
    io;
    return 0;
}
