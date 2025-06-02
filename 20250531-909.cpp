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

const long long MOD = 1000000007LL;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> mp(n * n + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mp[i * n + j + 1] = board[n - i - 1][(i & 1) ? n - j - 1 : j];
        vector<bool> vis(n * n + 1);
        vis[1] = true;
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (!q.empty())
        {
            auto [p, step] = q.front();
            q.pop();
            for (int i = p + 1; i <= min(n * n, p + 6); ++i)
            {
                int target = (mp[i] == -1) ? i : mp[i];
                if (target == n * n)
                    return step + 1;
                if (vis[target])
                    continue;
                vis[target] = true;
                q.emplace(target, step + 1);
            }
        }
        return -1;
    }
};

int main()
{
    io;
    return 0;
}
