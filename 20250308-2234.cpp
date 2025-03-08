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
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
    {
        long long n = flowers.size();
        long long left = newFlowers - n * target;
        for (int &f : flowers)
        {
            f = min(f, target);
            left += f;
        }
        if (left == newFlowers)
            return n * full;
        if (left >= 0)
            return max((target - 1ll) * partial + (n - 1) * full, n * full);
        sort(flowers.begin(), flowers.end());
        long long ans = 0;
        long long pre_sum = 0;
        long long j = 0;
        for (long long i = 1; i <= n; ++i)
        {
            left += target - flowers[i - 1];
            if (left < 0)
                continue;
            while (j < i && flowers[j] * j <= pre_sum + left)
            {
                pre_sum += flowers[j];
                ++j;
            }
            long long avg = (left + pre_sum) / j;
            long long beauty = avg * partial + (n - i) * full;
            ans = max(ans, beauty);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
