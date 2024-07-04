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
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        vector<int> pos;
        int c = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                cnt = 0;
                continue;
            }
            cnt++;
            c = max(c, cnt);
            pos.push_back(i);
        }
        c = min(c, min(3, k));
        if (maxChanges >= k - c)
            return max(c - 1, 0) + (k - c) * 2;

        int n = pos.size();
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + pos[i];

        long long ans = LLONG_MAX;
        int size = k - maxChanges;
        for (int r = size; r <= n; ++r)
        {
            int l = r - size;
            int i = l + size / 2;
            long long idx = pos[i];
            long long s1 = idx * (i - l) - (sum[i] - sum[l]);
            long long s2 = sum[r] - sum[i] - idx * (r - i);
            ans = min(ans, s1 + s2);
        }
        return ans + maxChanges * 2;
    }
};

int main()
{
    io;
    return 0;
}
