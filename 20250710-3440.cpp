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
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        startTime.push_back(eventTime);
        vector<pair<int, int>> m(3);
        m[0] = {startTime[0] - 0, -1};
        for (int i = 0; i < n; ++i)
        {
            int len = startTime[i + 1] - endTime[i];
            if (len < m[2].first)
                continue;
            if (len < m[1].first)
                m[2] = {len, i};
            else if (len < m[0].first)
            {
                m[2] = m[1];
                m[1] = {len, i};
            }
            else
            {
                m[2] = m[1];
                m[1] = m[0];
                m[0] = {len, i};
            }
        }
        int ans = 0;
        int sp1;
        int sp2 = startTime[0] - 0;
        for (int i = 0; i < n; ++i)
        {
            sp1 = sp2;
            sp2 = startTime[i + 1] - endTime[i];
            int idx;
            if (i - 1 == m[0].second && i == m[1].second || i - 1 == m[1].second && i == m[0].second)
                idx = 2;
            else if (i - 1 == m[0].second || i == m[0].second)
                idx = 1;
            else
                idx = 0;
            if (m[idx].first >= endTime[i] - startTime[i])
                ans = max(ans, sp1 + sp2 + endTime[i] - startTime[i]);
            else
                ans = max(ans, sp1 + sp2);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
