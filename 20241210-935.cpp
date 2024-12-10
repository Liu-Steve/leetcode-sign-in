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
    int knightDialer(int n)
    {
        vector<long long> dp1(10, 1);
        vector<long long> dp2(10);
        for (int i = 1; i < n; ++i)
        {
            dp2[0] = dp1[4] + dp1[6];
            dp2[1] = dp1[6] + dp1[8];
            dp2[2] = dp1[7] + dp1[9];
            dp2[3] = dp1[4] + dp1[8];
            dp2[4] = dp1[0] + dp1[3] + dp1[9];
            dp2[5] = 0;
            dp2[6] = dp1[0] + dp1[1] + dp1[7];
            dp2[7] = dp1[2] + dp1[6];
            dp2[8] = dp1[1] + dp1[3];
            dp2[9] = dp1[2] + dp1[4];
            for (int j = 0; j < 10; ++j)
                dp2[j] %= 1000000007LL;
            swap(dp1, dp2);
        }
        return reduce(dp1.begin(), dp1.end()) % 1000000007LL;
    }
};

int main()
{
    io;
    return 0;
}
