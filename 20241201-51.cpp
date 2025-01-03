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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> map(n, string(n, '.'));
        vector<bool> row(n), col(n), slash(2 * n - 1), bslash(2 * n - 1);
        auto dfs = [&](auto &&dfs, int x) -> void
        {
            if (x == n)
            {
                ans.emplace_back(map);
                return;
            }
            for (int y = 0; y < n; ++y)
            {
                if (row[x] || col[y] || slash[x + y] || bslash[x - y + n - 1])
                    continue;
                row[x] = true;
                col[y] = true;
                slash[x + y] = true;
                bslash[x - y + n - 1] = true;
                map[x][y] = 'Q';
                dfs(dfs, x + 1);
                row[x] = false;
                col[y] = false;
                slash[x + y] = false;
                bslash[x - y + n - 1] = false;
                map[x][y] = '.';
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}