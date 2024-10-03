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

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        const int INF = 0x3f3f3f3f;
        int n = passingFees.size();
        vector<vector<int>> f(maxTime + 1, vector<int>(n, INF));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; ++t)
            for (const auto &edge : edges)
            {
                int i = edge[0];
                int j = edge[1];
                int c = edge[2];
                if (c <= t)
                {
                    f[t][i] = min(f[t][i], f[t - c][j] + passingFees[i]);
                    f[t][j] = min(f[t][j], f[t - c][i] + passingFees[j]);
                }
            }
        int ans = INF;
        for (int t = 1; t <= maxTime; ++t)
            ans = min(ans, f[t][n - 1]);
        return ans == INF ? -1 : ans;
    }
};

int main()
{
    io;
    return 0;
}
