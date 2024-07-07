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
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
    {
        vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
        char r_color = color == 'B' ? 'W' : 'B';
        function<bool(int)> chk = [&](int idx)
        {
            int st = 0;
            int x = rMove + dx[idx];
            int y = cMove + dy[idx];
            while (x >= 0 && x < 8 && y >= 0 && y < 8)
            {
                if (st == 0)
                {
                    if (board[x][y] != r_color)
                        return false;
                    st = 1;
                }
                else if (st == 1)
                {
                    if (board[x][y] == color)
                        return true;
                    else if (board[x][y] == '.')
                        return false;
                }
                x += dx[idx];
                y += dy[idx];
            }
            return false;
        };
        for (int i = 0; i < 8; ++i)
            if (chk(i))
                return true;
        return false;
    }
};

int main()
{
    io;
    return 0;
}
