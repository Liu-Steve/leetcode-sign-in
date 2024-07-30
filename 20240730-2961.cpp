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
private:
    int qpow(int a, int b, int m)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % m;
            b >>= 1;
            a = (a * a) % m;
        }
        return ans % m;
    }

    int score(vector<int> &var)
    {
        int a = var[0], b = var[1], c = var[2], m = var[3];
        return qpow(qpow(a, b, 10), c, m);
    }

public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> ans;
        for (int i = 0; i < variables.size(); ++i)
            if (score(variables[i]) == target)
                ans.push_back(i);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
