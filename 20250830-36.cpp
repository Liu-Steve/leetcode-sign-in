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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            vector<int> ex(9);
            for (int j = 0; j < 9; ++j)
            {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                if (ex[ch - '1'] == 1)
                    return false;
                ex[ch - '1'] = 1;
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            vector<int> ex(9);
            for (int j = 0; j < 9; ++j)
            {
                char ch = board[j][i];
                if (ch == '.')
                    continue;
                if (ex[ch - '1'] == 1)
                    return false;
                ex[ch - '1'] = 1;
            }
        }
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
            {
                vector<int> ex(9);
                for (int n = 0; n < 3; ++n)
                    for (int m = 0; m < 3; ++m)
                    {
                        char ch = board[i + n][j + m];
                        if (ch == '.')
                            continue;
                        if (ex[ch - '1'] == 1)
                            return false;
                        ex[ch - '1'] = 1;
                    }
            }
        return true;
    }
};

int main()
{
    io;
    return 0;
}
