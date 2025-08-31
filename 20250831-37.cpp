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
    void solveSudoku(vector<vector<char>> &board)
    {
        vector row(9, vector<int>(9)), col(9, vector<int>(9)), blk(9, vector<int>(9));
        auto blkId = [&](int x, int y) -> int
        {
            return x / 3 * 3 + y / 3;
        };
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int ch = board[i][j] - '1';
                row[i][ch] = 1;
                col[j][ch] = 1;
                blk[blkId(i, j)][ch] = 1;
            }
        bool find = false;
        auto dfs = [&](auto &&dfs, int x, int y) -> void
        {
            if (x == 9)
                find = true;
            if (find)
                return;
            int next_x = x, next_y = y + 1;
            if (next_y == 9)
            {
                next_x = x + 1;
                next_y = 0;
            }
            if (board[x][y] != '.')
            {
                dfs(dfs, next_x, next_y);
                return;
            }
            int id = blkId(x, y);
            for (int ch = 0; ch < 9; ++ch)
            {
                if (row[x][ch] || col[y][ch] || blk[id][ch])
                    continue;
                row[x][ch] = 1;
                col[y][ch] = 1;
                blk[id][ch] = 1;
                board[x][y] = '1' + ch;
                dfs(dfs, next_x, next_y);
                if (find)
                    return;
                row[x][ch] = 0;
                col[y][ch] = 0;
                blk[id][ch] = 0;
                board[x][y] = '.';
            }
        };
        dfs(dfs, 0, 0);
    }
};

int main()
{
    io;
    return 0;
}
