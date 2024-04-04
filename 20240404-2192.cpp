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
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        queue<int> q;
        vector<int> cnt(n);
        vector<vector<int>> nxt(n);
        vector<set<int>> ancestor(n);
        for (auto &e : edges)
        {
            nxt[e[0]].push_back(e[1]);
            cnt[e[1]]++;
        }
        for (int i = 0; i < n; ++i)
            if (cnt[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int ch : nxt[node])
            {
                cnt[ch]--;
                if (cnt[ch] == 0)
                    q.push(ch);
                ancestor[ch].insert(node);
                ancestor[ch].insert(ancestor[node].begin(), ancestor[node].end());
            }
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i].assign(ancestor[i].begin(), ancestor[i].end());
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
