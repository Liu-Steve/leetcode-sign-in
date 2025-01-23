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
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> memo(n, vector<int>(14, -1));
        auto dfs = [&](auto &&dfs, int i, int j, int fa)
        {
            int &res = memo[i][j];
            if (res != -1)
                return res;
            int res1 = (coins[i] >> j) - k;
            int res2 = coins[i] >> (j + 1);
            for (int ch : g[i])
            {
                if (ch == fa)
                    continue;
                res1 += dfs(dfs, ch, j, i);
                if (j < 13)
                    res2 += dfs(dfs, ch, j + 1, i);
            }
            return res = max(res1, res2);
        };
        return dfs(dfs, 0, 0, -1);
    }
};

int main()
{
    io;
    return 0;
}
