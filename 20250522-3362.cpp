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
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        sort(queries.begin(), queries.end(), [&](vector<int> &q1, vector<int> &q2)
             { return q1[0] < q2[0]; });
        priority_queue<int> pq;
        vector<int> stop(n);
        int cnt = 0;
        int p = 0;
        for (int i = 0; i < n; ++i)
        {
            while (p < m && queries[p][0] <= i)
            {
                pq.push(queries[p][1]);
                p++;
            }
            while (cnt < nums[i] && !pq.empty() && pq.top() >= i)
            {
                cnt++;
                stop[pq.top()]++;
                pq.pop();
            }
            if (cnt < nums[i])
                return -1;
            cnt -= stop[i];
        }
        return pq.size();
    }
};

int main()
{
    io;
    return 0;
}
