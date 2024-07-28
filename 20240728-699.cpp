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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        int n = positions.size();
        vector<int> h(n);
        for (int i = 0; i < n; ++i)
        {
            int l1 = positions[i][0];
            int r1 = positions[i][0] + positions[i][1] - 1;
            h[i] = positions[i][1];
            for (int j = 0; j < i; ++j)
            {
                int l2 = positions[j][0];
                int r2 = positions[j][0] + positions[j][1] - 1;
                if (r1 >= l2 && r2 >= l1)
                    h[i] = max(h[i], h[j] + positions[i][1]);
            }
        }
        for (int i = 1; i < n; ++i)
            h[i] = max(h[i], h[i - 1]);
        return h;
    }
};

int main()
{
    io;
    return 0;
}
