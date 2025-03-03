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
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        vector<int> e1(26, INT32_MAX);
        vector<int> e2(26, INT32_MAX);
        for (int i = 0; i < points.size(); ++i)
        {
            int e = max(abs(points[i][0]), abs(points[i][1]));
            int c = s[i] - 'a';
            if (e < e1[c])
            {
                e2[c] = e1[c];
                e1[c] = e;
            }
            else if (e < e2[c])
                e2[c] = e;
        }
        int lmt = *min_element(e2.begin(), e2.end());
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            if (e1[i] < lmt)
                ans++;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
