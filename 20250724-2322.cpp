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
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> e(n);
        for (auto &v : edges)
        {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        int sum = reduce(nums.begin(), nums.end(), 0, bit_xor<int>());
        auto cal = [&](int p1, int p2, int p3) -> int
        {
            return max(p1, max(p2, p3)) - min(p1, min(p2, p3));
        };
        int ans = INT32_MAX;
        auto dfs2 = [&](auto &&dfs2, int x, int f, int oth, int anc) -> int
        {
            int son = nums[x];
            for (auto &y : e[x])
            {
                if (y == f)
                    continue;
                son ^= dfs2(dfs2, y, x, oth, anc);
            }
            if (f == anc)
                return son;
            ans = min(ans, cal(oth, son, sum ^ oth ^ son));
            return son;
        };
        auto dfs1 = [&](auto &&dfs1, int x, int f) -> int
        {
            int son = nums[x];
            for (auto &y : e[x])
            {
                if (y == f)
                    continue;
                son ^= dfs1(dfs1, y, x);
            }
            for (auto &y : e[x])
                if (y == f)
                    dfs2(dfs2, y, x, son, x);
            return son;
        };
        dfs1(dfs1, 0, -1);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
