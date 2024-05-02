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
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        int sum_q = 0;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j)
             { return wage[i] * quality[j] < wage[j] * quality[i]; });
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i)
        {
            pq.push(quality[id[i]]);
            sum_q += quality[id[i]];
        }
        double ans = sum_q * ((double)wage[id[k - 1]] / quality[id[k - 1]]);
        for (int i = k; i < n; ++i)
        {
            int q = quality[id[i]];
            if (q < pq.top())
            {
                sum_q -= pq.top() - q;
                pq.pop();
                pq.push(q);
                ans = min(ans, sum_q * ((double)wage[id[i]] / q));
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
