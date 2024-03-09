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
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll kSum(vi &nums, int k)
    {
        int n = nums.size();
        ll sum = 0;
        for (int &num : nums)
        {
            sum += max(0, num);
            num = abs(num);
        }
        sort(nums.begin(), nums.end());
        priority_queue<pr, vp, greater<pr>> pq;
        pq.emplace(0, 0);
        while (--k)
        {
            auto [val, pos] = pq.top();
            pq.pop();
            if (pos < n)
            {
                pq.emplace(val + nums[pos], pos + 1);
                if (pos)
                    pq.emplace(val - nums[pos - 1] + nums[pos], pos + 1);
            }
        }
        return sum - pq.top().first;
    }
};

int main()
{
    io;
    return 0;
}
