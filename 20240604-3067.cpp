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
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> nei(n);
        for (auto &e : edges)
        {
            nei[e[0]].emplace_back(e[1], e[2] % signalSpeed);
            nei[e[1]].emplace_back(e[0], e[2] % signalSpeed);
        }
        unordered_map<int, vector<int>> mem;
        function<vector<int>(int, int, int)> dfs = [&](int a, int b, int w) -> vector<int>{
            int key = (a << 10) | b;
            if (mem.count(key))
                return mem[key];
            vector<int> cnt(signalSpeed);
            for (auto [c, ww] : nei[b])
            {
                if (c == a)
                    continue;
                vector<int> subcnt = dfs(b, c, ww);
                for (int i = 0; i < signalSpeed; ++i)
                    cnt[i] += subcnt[(i + w) % signalSpeed];
            }
            mem[key] = cnt;
            return cnt;
        };
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (auto [b, w] : nei[i])
            {
                vector<int> cnt = dfs(i, b, w);
                ans[i] += sum * cnt[0];
                sum += cnt[0];
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
