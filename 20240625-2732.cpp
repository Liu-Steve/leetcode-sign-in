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
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid)
    {
        function<int(vector<int> &)> val = [&](vector<int> &line) -> int
        {
            int num = 0;
            for (int ele : line)
            {
                num <<= 1;
                num |= ele;
            }
            return num;
        };
        vector<int> id(32, -1);
        for (int i = grid.size() - 1; i >= 0; --i)
        {
            int num = val(grid[i]);
            id[num] = i;
        }
        if (id[0] != -1)
            return vector<int>{id[0]};
        for (int i = 1; i < 32; ++i)
            for (int j = i + 1; j < 32; ++j)
            {
                if ((i & j) != 0)
                    continue;
                if (id[i] == -1 || id[j] == -1)
                    continue;
                return vector<int>{min(id[i], id[j]), max(id[i], id[j])};
            }
        return vector<int>{};
    }
};

int main()
{
    io;
    return 0;
}
