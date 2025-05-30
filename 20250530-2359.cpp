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

const long long MOD = 1000000007LL;

class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dis1(n, INT32_MAX), dis2(n, INT32_MAX);
        auto f = [&](auto &&f, vector<int> &dis, int node, int d)
        {
            if (dis[node] != INT32_MAX)
                return;
            dis[node] = d;
            if (edges[node] == -1)
                return;
            f(f, dis, edges[node], d + 1);
        };
        f(f, dis1, node1, 0);
        f(f, dis2, node2, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i)
            if (max(dis1[i], dis2[i]) < max(dis1[ans], dis2[ans]))
                ans = i;
        if (max(dis1[ans], dis2[ans]) == INT32_MAX)
            return -1;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
