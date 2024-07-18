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
    vi minimumTime(int n, vv &edges, vi &disappear)
    {
        vector<vp> nxt(n);
        for (auto &e : edges)
        {
            nxt[e[0]].emplace_back(e[1], e[2]);
            nxt[e[1]].emplace_back(e[0], e[2]);
        }
        priority_queue<pr, vp, greater<pr>> pq;
        vi d(n, INT32_MAX);
        pq.emplace(0, 0);
        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis >= disappear[node])
                continue;
            if (d[node] <= dis)
                continue;
            d[node] = dis;
            for (auto [n_node, n_e] : nxt[node])
                pq.emplace(dis + n_e, n_node);
        }
        for (int &ele : d)
            if (ele == INT32_MAX)
                ele = -1;
        return d;
    }
};

int main()
{
    io;
    return 0;
}
