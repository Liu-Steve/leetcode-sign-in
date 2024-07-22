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
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> nxt(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j &&
                    (long long)(bombs[i][0] - bombs[j][0]) *
                                (bombs[i][0] - bombs[j][0]) +
                            (long long)(bombs[i][1] - bombs[j][1]) *
                                (bombs[i][1] - bombs[j][1]) <=
                        (long long)bombs[i][2] * bombs[i][2])
                    nxt[i].push_back(j);
        vector<int> vis(n);
        function<void(int)> dfs = [&](int root)
        {
            if (vis[root])
                return;
            vis[root] = 1;
            for (int node : nxt[root])
                dfs(node);
        };
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            fill(vis.begin(), vis.end(), 0);
            dfs(i);
            int cnt = reduce(vis.begin(), vis.end());
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
