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
    int minFlips(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m - i - 1; ++i)
        {
            for (int j = 0; j < n - j - 1; ++j)
            {
                int cnt = grid[i][j] + grid[i][n - j - 1] + grid[m - i - 1][j] + grid[m - i - 1][n - j - 1];
                ans += min(cnt, 4 - cnt);
            }
        }
        bool odd = false;
        int cnt = 0;
        if ((m & 1) == 1)
            for (int j = 0; j < n - j - 1; ++j)
            {
                if (grid[m / 2][j] != grid[m / 2][n - j - 1])
                {
                    odd = true;
                    ans++;
                }
                else if (grid[m / 2][j] == 1)
                    cnt++;
            }
        if ((n & 1) == 1)
            for (int i = 0; i < m - i - 1; ++i)
            {
                if (grid[i][n / 2] != grid[m - i - 1][n / 2])
                {
                    odd = true;
                    ans++;
                }
                else if (grid[i][n / 2] == 1)
                    cnt++;
            }
        if (!odd && (cnt & 1))
            ans += 2;
        if ((m & 1) == 1 && (n & 1) == 1)
            ans += grid[m / 2][n / 2];
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
