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
    long long quickMul(long long x, long long y, long long m)
    {
        long long res = 1;
        while (y)
        {
            if (y & 1)
            {
                res = (res * x) % m;
            }
            y >>= 1;
            x = (x * x) % m;
        }
        return res;
    }

    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        if (multiplier == 1)
        {
            return nums;
        }
        long long n = nums.size(), m = 1e9 + 7;
        long long mx = *max_element(nums.begin(), nums.end());
        vector<pair<long long, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {nums[i], i};
        }
        make_heap(v.begin(), v.end(), greater<>());
        for (; v[0].first < mx && k; k--)
        {
            pop_heap(v.begin(), v.end(), greater<>());
            v.back().first *= multiplier;
            push_heap(v.begin(), v.end(), greater<>());
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            int t = k / n + (i < k % n);
            nums[v[i].second] = ((v[i].first % m) * quickMul(multiplier, t, m)) % m;
        }
        return nums;
    }
};

int main()
{
    io;
    return 0;
}
