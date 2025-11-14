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

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector ans(n, vector(n, 0));
        for (auto &q : queries)
        {
            ans[q[0]][q[1]]++;
            if (q[2] + 1 < n)
                ans[q[2] + 1][q[1]]--;
            if (q[3] + 1 < n)
                ans[q[0]][q[3] + 1]--;
            if (q[2] + 1 < n && q[3] + 1 < n)
                ans[q[2] + 1][q[3] + 1]++;
        }
        for (int i = 0; i < n; ++i)
        {
            int lst = 0;
            for (int j = 0; j < n; ++j)
            {
                lst += ans[i][j];
                ans[i][j] = lst;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int lst = 0;
            for (int j = 0; j < n; ++j)
            {
                lst += ans[j][i];
                ans[j][i] = lst;
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
