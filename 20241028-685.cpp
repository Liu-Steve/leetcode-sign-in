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

class DSet
{
private:
    int *fa;
    int n;
    int findFa(int node)
    {
        while (fa[node] >= 0)
        {
            node = fa[node];
        }
        return node;
    }

public:
    DSet(int n)
    {
        fa = new int[n];
        for (int i = 0; i < n; ++i)
            fa[i] = -1;
    }

    bool find(int n1, int n2)
    {
        return findFa(n1) == findFa(n2);
    }

    void add(int n1, int n2)
    {
        int fa1 = findFa(n1);
        int fa2 = findFa(n2);
        if (fa1 == fa2)
            return;
        if (fa[fa1] > fa[fa2])
        {
            fa[fa2] += fa[fa1];
            fa[fa1] = fa2;
        }
        else
        {
            fa[fa1] += fa[fa2];
            fa[fa2] = fa1;
        }
    }
};

class Solution
{
private:
    int isTree(vector<vector<int>> &edges, int ban = -1)
    {
        int n = edges.size();
        DSet d(n + 1);
        for (int i = 0; i < n; ++i)
        {
            if (i == ban)
                continue;
            if (d.find(edges[i][0], edges[i][1]))
                return i;
            d.add(edges[i][0], edges[i][1]);
        }
        return -1;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> in(n + 1);
        for (int i = 0; i < n; ++i)
            in[edges[i][1]].push_back(i);
        int target = -1;
        for (int i = 1; i <= n; ++i)
            if (in[i].size() == 2)
            {
                target = i;
                break;
            }
        if (target == -1)
            return edges[isTree(edges)];
        if (isTree(edges, in[target][1]) == -1)
            return edges[in[target][1]];
        return edges[in[target][0]];
    }
};

int main()
{
    io;
    return 0;
}
