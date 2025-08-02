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
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> cnt;
        for (int i = 0; i < basket1.size(); ++i)
        {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        vector<int> a;
        int mn = INT32_MAX;
        for (auto [x, c] : cnt)
        {
            if (c & 1)
                return -1;
            mn = min(mn, x);
            for (c = abs(c) / 2; c > 0; c--)
                a.push_back(x);
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < a.size() / 2; ++i)
            ans += min(a[i], mn * 2);
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
