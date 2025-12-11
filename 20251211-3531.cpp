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
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> range_x(n + 1), range_y(n + 1);
        for (auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            if (range_x[x].first == 0)
                range_x[x] = {y, y};
            else
            {
                range_x[x].first = min(range_x[x].first, y);
                range_x[x].second = max(range_x[x].second, y);
            }
            if (range_y[y].first == 0)
                range_y[y] = {x, x};
            else
            {
                range_y[y].first = min(range_y[y].first, x);
                range_y[y].second = max(range_y[y].second, x);
            }
        }
        int ans = 0;
        for (auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            if (range_x[x].first < y &&
                y < range_x[x].second &&
                range_y[y].first < x &&
                x < range_y[y].second)
                ans++;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
