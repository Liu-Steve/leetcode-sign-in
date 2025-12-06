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

constexpr long long MOD = 1000000007LL;

class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> min_q, max_q;
        vector<int> f(n + 1);
        f[0] = 1;
        long long sum_f = 0;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            sum_f += f[i];
            while (!min_q.empty() && x <= nums[min_q.back()])
                min_q.pop_back();
            min_q.push_back(i);
            while (!max_q.empty() && x >= nums[max_q.back()])
                max_q.pop_back();
            max_q.push_back(i);
            while (nums[max_q.front()] - nums[min_q.front()] > k)
            {
                sum_f -= f[left];
                left++;
                if (min_q.front() < left)
                    min_q.pop_front();
                if (max_q.front() < left)
                    max_q.pop_front();
            }
            f[i + 1] = sum_f % MOD;
        }
        return f[n];
    }
};

int main()
{
    io;
    return 0;
}
