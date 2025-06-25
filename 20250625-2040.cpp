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
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        long long p1 = lower_bound(nums1.begin(), nums1.end(), 0) - nums1.begin();
        long long p2 = lower_bound(nums2.begin(), nums2.end(), 0) - nums2.begin();
        vector<int> v[4];
        for (int i = p1 - 1; i >= 0; --i)
            v[0].push_back(-nums1[i]);
        for (int i = p1; i < n1; ++i)
            v[1].push_back(nums1[i]);
        for (int i = p2 - 1; i >= 0; --i)
            v[2].push_back(-nums2[i]);
        for (int i = p2; i < n2; ++i)
            v[3].push_back(nums2[i]);
        long long neg_sum = p1 * (n2 - p2) + (n1 - p1) * p2;
        bool neg;
        if (neg_sum >= k)
        {
            k = neg_sum - k + 1;
            swap(v[2], v[3]);
            neg = true;
        }
        else
        {
            k -= neg_sum;
            neg = false;
        }
        auto cnt = [&](vector<int> &v1, vector<int> &v2, long long limit) -> long long
        {
            long long ans = 0;
            int j = v2.size() - 1;
            for (int i = 0; i < v1.size(); ++i)
            {
                while (j >= 0 && (long long)v1[i] * v2[j] > limit)
                    j--;
                ans += j + 1;
            }
            return ans;
        };
        if (cnt(v[0], v[2], 0) + cnt(v[1], v[3], 0) >= k)
            return 0;
        long long l = 0, r = 1e10 + 10;
        while (l + 1 < r)
        {
            long long m = (l + r) / 2;
            long long num = cnt(v[0], v[2], m) + cnt(v[1], v[3], m);
            if (num >= k)
                r = m;
            else
                l = m;
        }
        return neg ? -r : r;
    }
};

int main()
{
    io;
    return 0;
}
