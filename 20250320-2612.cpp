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
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k)
    {
        unordered_set<int> ban{banned.begin(), banned.end()};
        set<int> indices[2];
        for (int i = 0; i < n; ++i)
            if (i != p && !ban.count(i))
                indices[i % 2].insert(i);
        indices[0].insert(n);
        indices[1].insert(n);

        vector<int> ans(n, -1);
        ans[p] = 0;
        for (int b : banned)
            ans[b] = -1;
        queue<int> q;
        q.push(p);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            int l = max(t - k + 1, k - t - 1);
            int r = min(t + k - 1, 2 * n - k - t - 1);
            auto &st = indices[l % 2];
            for (auto i = st.lower_bound(l); *i <= r; i = st.erase(i))
            {
                ans[*i] = ans[t] + 1;
                q.push(*i);
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
