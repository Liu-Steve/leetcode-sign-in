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

class UnionFind
{
public:
    vector<int> fa;
    UnionFind(int n) : fa(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int x)
    {
        if (fa[x] != x)
            fa[x] = find(fa[x]);
        return fa[x];
    }
    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
    void merge(int from, int to)
    {
        int x = find(from), y = find(to);
        fa[x] = y;
    }
};

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        ranges::sort(meetings, {}, [](auto &a)
                     { return a[2]; });
        UnionFind uf(n);
        uf.merge(firstPerson, 0);
        int m = meetings.size();
        for (int i = 0; i < m;)
        {
            int start = i;
            int time = meetings[i][2];
            for (; i < m && meetings[i][2] == time; i++)
                uf.merge(meetings[i][0], meetings[i][1]);
            for (int j = start; j < i; j++)
            {
                int x = meetings[j][0], y = meetings[j][1];
                if (!uf.is_same(x, 0))
                    uf.fa[x] = x;
                if (!uf.is_same(y, 0))
                    uf.fa[y] = y;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (uf.is_same(i, 0))
                ans.push_back(i);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
