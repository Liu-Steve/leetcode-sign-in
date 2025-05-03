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
#define MAX_N 10000
#define MAX_E 13

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

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        auto rot = [&](int target)
        {
            int cnt_top = 0;
            int cnt_bottom = 0;
            for (int i = 0; i < n; ++i)
            {
                if (tops[i] != target && bottoms[i] != target)
                    return INT32_MAX;
                if (tops[i] != target)
                    cnt_bottom++;
                else if (bottoms[i] != target)
                    cnt_top++;
            }
            return min(cnt_top, cnt_bottom);
        };
        int ans = min(rot(tops[0]), rot(bottoms[0]));
        return ans == INT32_MAX ? -1 : ans;
    }
};

int main()
{
    io;
    return 0;
}
