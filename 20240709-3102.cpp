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
    int minimumDistance(vector<vector<int>> &points)
    {
        auto d1 = [&](int p)
        {
            return points[p][0] + points[p][1];
        };
        auto d2 = [&](int p)
        {
            return points[p][0] - points[p][1];
        };
        int n = points.size();
        vector<int> idx1(n);
        vector<int> idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int p1, int p2)
             { return d1(p1) > d1(p2); });
        sort(idx2.begin(), idx2.end(), [&](int p1, int p2)
             { return d2(p1) > d2(p2); });
        int ans = INT32_MAX;
        vector<vector<int>> ps = {{idx1[0], idx1[1]}, {idx1[n - 1], idx1[n - 2]}, {idx2[0], idx2[1]}, {idx2[n - 1], idx2[n - 2]}};
        for (int i = 0; i < 4; ++i)
        {
            int r = ps[i][0];
            vector<int> pick(4);
            for (int j = 0; j < 4; ++j)
                pick[j] = (ps[j][0] == r ? ps[j][1] : ps[j][0]);
            ans = min(ans, max(d1(pick[0]) - d1(pick[1]), d2(pick[2]) - d2(pick[3])));
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
