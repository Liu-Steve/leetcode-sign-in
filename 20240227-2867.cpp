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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        vector<int> pri;
        vector<uint8_t> not_prime(n + 1); // bool
        not_prime[0] = true;
        not_prime[1] = true;
        for (int i = 2; i <= n; ++i)
        {
            if (!not_prime[i])
                pri.push_back(i);
            for (int pri_j : pri)
            {
                if (pri_j * i > n)
                    break;
                not_prime[pri_j * i] = true;
                if (i % pri_j == 0)
                    break;
            }
        }

        vector<vector<int>> nei(n + 1);
        vector<int> val(n + 1);
        for (auto &e : edges)
        {
            nei[e[0]].push_back(e[1]);
            nei[e[1]].push_back(e[0]);
        }

        vector<int> nodes;
        int cnt = 0;
        function<void(int)> dfs = [&](int root) -> void
        {
            if (!not_prime[root] || val[root] != 0)
                return;
            cnt++;
            nodes.push_back(root);
            val[root] = -1;
            for (int nxt : nei[root])
                dfs(nxt);
        };
        for (int i = 1; i <= n; ++i)
        {
            if (!not_prime[i] || val[i] != 0)
                continue;
            nodes.clear();
            cnt = 0;
            dfs(i);
            for (int nd : nodes)
                val[nd] = cnt;
        }
        long long ans = 0;
        for (int p : pri)
        {
            if (p > n)
                break;
            long long num = 1;
            for (int g : nei[p])
            {
                ans += val[g] * num;
                num += val[g];
            }
        }
        return ans;
    }
};

int main()
{
    io;

    Solution s;
    vector<vector<int>> e = {{1,2},{1,3},{2,4},{2,5}};
    cout << s.countPaths(5, e);

    return 0;
}
