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
    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
    {
        vector<vector<int>> g(n);
        for (auto &e : hierarchy)
            g[e[0] - 1].push_back(e[1] - 1);
        auto dfs = [&](auto &&dfs, int x) -> array<vector<int>, 2>
        {
            vector<int> sub_f[2]{vector<int>(budget + 1, INT_MIN / 2), vector<int>(budget + 1, INT_MIN / 2)};
            sub_f[0][0] = sub_f[1][0] = 0;
            for (int y : g[x])
            {
                auto fy = dfs(dfs, y);
                for (int k = 0; k < 2; k++)
                {
                    vector<int> nf(budget + 1, INT_MIN / 2);
                    nf[0] = 0;
                    for (int jy = 0; jy <= budget; jy++)
                    {
                        int res_y = fy[k][jy];
                        if (res_y < 0)
                            continue;
                        for (int j = jy; j <= budget; j++)
                            nf[j] = max(nf[j], sub_f[k][j - jy] + res_y);
                    }
                    sub_f[k] = move(nf);
                }
            }
            array<vector<int>, 2> f;
            for (int k = 0; k < 2; k++)
            {
                f[k] = sub_f[0];
                int cost = present[x] / (k + 1);
                for (int j = cost; j <= budget; j++)
                    f[k][j] = max(f[k][j], sub_f[1][j - cost] + future[x] - cost);
            }
            return f;
        };
        auto ans = dfs(dfs, 0)[0];
        return *max_element(ans.begin(), ans.end());
    }
};

int main()
{
    io;
    return 0;
}
