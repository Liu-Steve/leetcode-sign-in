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

class NeighborSum
{
private:
    vector<int> ans1, ans2;

public:
    NeighborSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        ans1.resize(n * n);
        ans2.resize(n * n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cnt1 = 0;
                int cnt2 = 0;
                if (i > 0)
                    cnt1 += grid[i - 1][j];
                if (j > 0)
                    cnt1 += grid[i][j - 1];
                if (i < n - 1)
                    cnt1 += grid[i + 1][j];
                if (j < n - 1)
                    cnt1 += grid[i][j + 1];
                if (i > 0 && j > 0)
                    cnt2 += grid[i - 1][j - 1];
                if (i > 0 && j < n - 1)
                    cnt2 += grid[i - 1][j + 1];
                if (i < n - 1 && j > 0)
                    cnt2 += grid[i + 1][j - 1];
                if (i < n - 1 && j < n - 1)
                    cnt2 += grid[i + 1][j + 1];
                ans1[grid[i][j]] = cnt1;
                ans2[grid[i][j]] = cnt2;
            }
        }
    }

    int adjacentSum(int value)
    {
        return ans1[value];
    }

    int diagonalSum(int value)
    {
        return ans2[value];
    }
};

int main()
{
    io;
    return 0;
}
