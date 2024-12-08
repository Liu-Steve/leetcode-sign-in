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
    int movesToChessboard(vector<vector<int>> &board)
    {
        int ans = 0;
        int n = board.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += board[0][i];
        if (abs(n - cnt * 2) > 1)
            return -1;
        cnt = 1;
        int diff = board[0][0];
        for (int i = 1; i < n; i++)
        {
            cnt += (board[i][0] == board[0][0]);
            diff += ((board[i][0] ^ i) & 1);
            for (int j = 0; j < n; ++j)
                if (board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j])
                    return -1;
        }
        if (abs(n - cnt * 2) > 1)
            return -1;
        if (n & 1)
            ans += (diff & 1) ? (n - diff) / 2 : diff / 2;
        else
            ans += min(diff, n - diff) / 2;
        diff = 0;
        for (int i = 0; i < n; ++i)
            diff += ((board[0][i] ^ i) & 1);
        if (n & 1)
            ans += (diff & 1) ? (n - diff) / 2 : diff / 2;
        else
            ans += min(diff, n - diff) / 2;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
