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

class DSet
{
public:
    vector<int> fa;

    DSet(int n) : fa(n, -1)
    {
    }

    int findFa(int node)
    {
        while (fa[node] >= 0)
        {
            node = fa[node];
        }
        return node;
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            auto &a = accounts[i];
            for (int j = 1; j < a.size(); ++j)
                mp[a[j]].push_back(i);
        }
        DSet d(n);
        for (auto &[s, idx] : mp)
        {
            if (idx.size() < 2)
                continue;
            for (int i = 1; i < idx.size(); ++i)
                d.add(idx[0], idx[i]);
        }
        unordered_map<int, vector<string>> peo;
        for (auto &[s, idx] : mp)
            peo[d.findFa(idx[0])].push_back(s);
        vector<vector<string>> ans;
        for (auto &[i, e] : peo)
        {
            sort(e.begin(), e.end());
            ans.emplace_back();
            ans.back().push_back(accounts[i][0]);
            for (auto &s : e)
                ans.back().push_back(s);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
