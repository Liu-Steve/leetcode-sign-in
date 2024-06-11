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
    int countBattleships(vector<vector<char>> &board)
    {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'X')
                {
                    if (i > 0 && board[i - 1][j] == 'X' || i < m - 1 && board[i + 1][j] == 'X')
                        continue;
                    ans++;
                    while (j < n && board[i][j] == 'X')
                        j++;
                }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (board[j][i] == 'X')
                {
                    if (i > 0 && board[j][i - 1] == 'X' || i < n - 1 && board[j][i + 1] == 'X')
                        continue;
                    if (j == m - 1 || board[j + 1][i] == '.')
                        continue;
                    ans++;
                    while (j < m && board[j][i] == 'X')
                        j++;
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
