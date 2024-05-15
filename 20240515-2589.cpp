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
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int> &t1, vector<int> &t2)
             { return t1[1] < t2[1]; });
        int ans = 0;
        vector<int> run(tasks.back()[1] + 1);
        for (auto &t : tasks)
        {
            int l = t[0], r = t[1], d = t[2];
            d -= reduce(run.begin() + l, run.begin() + r + 1);
            for (int i = r; d > 0; --i)
            {
                if (run[i])
                    continue;
                run[i] = true;
                d--;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
