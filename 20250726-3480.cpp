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
    long long maxSubarrays(int n, vector<vector<int>> &pairs)
    {
        int m = pairs.size();
        vector col(n + 1, vector<int>());
        for (int i = 0; i < m; ++i)
        {
            col[pairs[i][0]].push_back(i + 1);
            col[pairs[i][1]].push_back(i + 1);
        }
        vector<int> f(n + 1), g(n + 1), h(n + 1);
        vector<long long> cnt(m + 1);
        int bad = 0;
        for (int i = 1, j = 1; i <= n; ++i)
        {
            for (int x : col[i])
                if (++cnt[x] == 2)
                    bad++;
            while (j <= i && bad > 0)
            {
                for (int x : col[j])
                    if (--cnt[x] == 1)
                        bad--;
                j++;
            }
            f[i] = i - j + 1;
        }
        cnt.assign(m + 1, 0);
        bad = 0;
        long long sm = 0;
        for (int i = 1, j = 1; i <= n; ++i)
        {
            for (int x : col[i])
                if (++cnt[x] == 2)
                    bad++, sm += x;
            while (j <= i && bad > 1)
            {
                for (int x : col[j])
                    if (--cnt[x] == 1)
                        bad--, sm -= x;
                j++;
            }
            g[i] = i - j + 1;
            h[i] = sm;
        }
        cnt.assign(m + 1, 0);
        long long base = 0;
        for (int i = 1; i <= n; ++i)
        {
            base += f[i];
            cnt[h[i]] += g[i] - f[i];
        }
        return base + *max_element(cnt.begin() + 1, cnt.end());
    }
};

int main()
{
    io;
    return 0;
}
