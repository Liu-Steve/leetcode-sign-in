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
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Graph
{
private:
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> d;

public:
    Graph(int n, vector<vector<int>> &edges) : d(n, vector<int>(n, INF))
    {
        for (auto &e : edges)
            d[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    void addEdge(vector<int> e)
    {
        int n = d.size();
        if (d[e[0]][e[1]] <= e[2])
            return;
        d[e[0]][e[1]] = e[2];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][e[0]] + e[2] + d[e[1]][j]);
    }

    int shortestPath(int node1, int node2)
    {
        return d[node1][node2] == INF ? -1 : d[node1][node2];
    }
};

int main()
{
    io;
    return 0;
}
