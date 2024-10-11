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
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, long long> cnt1;
        unordered_map<int, long long> cnt2;
        for (int num : nums1)
            cnt1[num]++;
        for (int num : nums2)
            cnt2[num]++;
        int max1 = *max_element(nums1.begin(), nums1.end());
        for (auto [num, val] : cnt2)
        {
            int m = num * k;
            for (int i = 1; m <= max1; i++)
            {
                m = num * k * i;
                if (cnt1.count(m))
                    ans += cnt1[m] * val;
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
