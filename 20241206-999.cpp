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
    int numRookCaptures(vector<vector<char>> &board)
    {
        int x = -1;
        int y = -1;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                }
        int ans = 0;
        for (int i = x + 1; i < 8; ++i)
        {
            if (board[i][y] == 'B')
                break;
            if (board[i][y] == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = x - 1; i >= 0; --i)
        {
            if (board[i][y] == 'B')
                break;
            if (board[i][y] == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = y + 1; i < 8; ++i)
        {
            if (board[x][i] == 'B')
                break;
            if (board[x][i] == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = y - 1; i >= 0; --i)
        {
            if (board[x][i] == 'B')
                break;
            if (board[x][i] == 'p')
            {
                ans++;
                break;
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
