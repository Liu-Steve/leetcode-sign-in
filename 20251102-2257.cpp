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
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector mp(m, vector<int>(n));
        for (auto &g : guards)
            mp[g[0]][g[1]] = 2;
        for (auto &w : walls)
            mp[w[0]][w[1]] = 3;
        for (int i = 0; i < m; ++i)
        {
            int lst = 3;
            for (int j = 0; j < n; ++j)
                if (mp[i][j] == 2 || mp[i][j] == 3)
                    lst = mp[i][j];
                else if (lst == 2)
                    mp[i][j] = 1;
            lst = 3;
            for (int j = n - 1; j >= 0; --j)
                if (mp[i][j] == 2 || mp[i][j] == 3)
                    lst = mp[i][j];
                else if (lst == 2)
                    mp[i][j] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            int lst = 3;
            for (int i = 0; i < m; ++i)
                if (mp[i][j] == 2 || mp[i][j] == 3)
                    lst = mp[i][j];
                else if (lst == 2)
                    mp[i][j] = 1;
            lst = 3;
            for (int i = m - 1; i >= 0; --i)
                if (mp[i][j] == 2 || mp[i][j] == 3)
                    lst = mp[i][j];
                else if (lst == 2)
                    mp[i][j] = 1;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mp[i][j] == 0)
                    ans++;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
