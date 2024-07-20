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
    int minimumMoves(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> from, to;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                if (!grid[i][j])
                {
                    to.emplace_back(i, j);
                    continue;
                }
                for (int k = 1; k < grid[i][j]; ++k)
                    from.emplace_back(i, j);
            }
        int ans = INT32_MAX;
        do
        {
            int total = 0;
            for (int i = 0; i < from.size(); ++i)
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            ans = min(ans, total);
        } while (next_permutation(from.begin(), from.end()));
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
