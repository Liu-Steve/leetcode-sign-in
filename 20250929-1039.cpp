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
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        unordered_map<int, int> mem;
        auto h = [&](int i, int j) -> int
        {
            return i * n + j;
        };
        auto dfs = [&](auto &&dfs, int i, int j) -> int
        {
            if (mem.count(h(i, j)))
                return mem[h(i, j)];
            if ((j - i + n) % n == 1)
            {
                mem[h(i, j)] = 0;
                return 0;
            }
            if ((j - i + n) % n == 2)
            {
                int idx = (i + 1) % n;
                mem[h(i, j)] = values[i] * values[j] * values[idx];
                return mem[h(i, j)];
            }
            int ans = INT32_MAX;
            for (int k = (i + 1) % n; k != j; k = (k + 1) % n)
            {
                int cnt = values[i] * values[j] * values[k];
                cnt += dfs(dfs, i, k) + dfs(dfs, k, j);
                ans = min(ans, cnt);
            }
            mem[h(i, j)] = ans;
            return ans;
        };
        return dfs(dfs, 1, 0);
    }
};

int main()
{
    io;
    return 0;
}
