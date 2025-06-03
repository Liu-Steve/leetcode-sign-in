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

const long long MOD = 1000000007LL;

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int ans = 0;
        int n = status.size();
        vector<uint8_t> vis(n), box(n);
        queue<int> q;
        for (int b : initialBoxes)
        {
            box[b] = 1;
            if (status[b] == 0)
                continue;
            q.push(b);
            vis[b] = true;
        }
        while (!q.empty())
        {
            int b = q.front();
            q.pop();
            ans += candies[b];
            for (int k : keys[b])
            {
                status[k] = 1;
                if (box[k] && !vis[k])
                {
                    q.push(k);
                    vis[k] = true;
                }
            }
            for (int c : containedBoxes[b])
            {
                box[c] = 1;
                if (status[c] && !vis[c])
                {
                    q.push(c);
                    vis[c] = true;
                }
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
