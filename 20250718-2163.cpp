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
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        vector<long long> post(n + 1);
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 3 * n - 1; i >= 2 * n; --i)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        post[n] = sum;
        for (int i = 2 * n - 1; i >= n; --i)
        {
            sum += nums[i];
            pq.push(nums[i]);
            sum -= pq.top();
            pq.pop();
            post[i - n] = sum;
        }
        sum = 0;
        priority_queue<int> pq1;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            pq1.push(nums[i]);
        }
        long long ans = sum - post[0];
        for (int i = n; i < 2 * n; ++i)
        {
            sum += nums[i];
            pq1.push(nums[i]);
            sum -= pq1.top();
            pq1.pop();
            ans = min(ans, sum - post[i - n + 1]);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
