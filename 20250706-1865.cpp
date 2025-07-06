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

class FindSumPairs
{
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> cnt2;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2) : nums1(nums1), nums2(nums2)
    {
        for (int num : nums2)
            cnt2[num]++;
    }

    void add(int index, int val)
    {
        cnt2[nums2[index]]--;
        nums2[index] += val;
        cnt2[nums2[index]]++;
    }

    int count(int tot)
    {
        int ans = 0;
        for (int num : nums1)
            if (cnt2.count(tot - num))
                ans += cnt2[tot - num];
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
