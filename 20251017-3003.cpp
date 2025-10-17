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
    int maxPartitionsAfterOperations(string s, int k)
    {
        if (k == 26)
            return 1;
        int n = s.size();
        vector<int> preSeq(n + 1), preMask(n + 1), preSize(n + 1),
            sufSeq(n + 1), sufMask(n + 1), sufSize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int bias = (1 << (s[i] - 'a'));
            if (!(preMask[i] & bias) && preSize[i] == k)
            {
                preSeq[i + 1] = preSeq[i] + 1;
                preMask[i + 1] = bias;
                preSize[i + 1] = 1;
            }
            else
            {
                preSeq[i + 1] = preSeq[i];
                preMask[i + 1] = preMask[i] | bias;
                preSize[i + 1] = preSize[i] + (preMask[i + 1] != preMask[i]);
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            int bias = (1 << (s[i] - 'a'));
            if (!(sufMask[i + 1] & bias) && sufSize[i + 1] == k)
            {
                sufSeq[i] = sufSeq[i + 1] + 1;
                sufMask[i] = bias;
                sufSize[i] = 1;
            }
            else
            {
                sufSeq[i] = sufSeq[i + 1];
                sufMask[i] = sufMask[i + 1] | bias;
                sufSize[i] = sufSize[i + 1] + (sufMask[i] != sufMask[i + 1]);
            }
        }
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            int unionMask = (preMask[i] | sufMask[i + 1]);
            int unionSize = __popcount(unionMask);
            if (unionSize < k)
                ans = max(ans, preSeq[i] + sufSeq[i + 1] + 1);
            else if (unionSize < 26 && preSize[i] == k && sufSize[i + 1] == k)
                ans = max(ans, preSeq[i] + sufSeq[i + 1] + 3);
            else
                ans = max(ans, preSeq[i] + sufSeq[i + 1] + 2);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
