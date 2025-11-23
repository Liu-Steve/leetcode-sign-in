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
    int maxSumDivThree(vector<int> &nums)
    {
        int sum = 0;
        int r1p1 = INT32_MAX;
        int r1p2 = INT32_MAX;
        int r2p1 = INT32_MAX;
        int r2p2 = INT32_MAX;
        for (int num : nums)
        {
            sum += num;
            if (num % 3 == 0)
                continue;
            if (num % 3 == 1)
            {
                if (num < r1p1)
                {
                    r1p2 = r1p1;
                    r1p1 = num;
                }
                else if (num < r1p2)
                    r1p2 = num;
            }
            else
            {
                if (num < r2p1)
                {
                    r2p2 = r2p1;
                    r2p1 = num;
                }
                else if (num < r2p2)
                    r2p2 = num;
            }
        }
        if (sum % 3 == 0)
            return sum;
        else if (sum % 3 == 1)
        {
            if (r1p1 == INT32_MAX)
                return sum - r2p1 - r2p2;
            if (r2p2 == INT32_MAX)
                return sum - r1p1;
            return max(sum - r2p1 - r2p2, sum - r1p1);
        }
        else
        {
            if (r2p1 == INT32_MAX)
                return sum - r1p1 - r1p2;
            if (r1p2 == INT32_MAX)
                return sum - r2p1;
            return max(sum - r1p1 - r1p2, sum - r2p1);
        }
    }
};

int main()
{
    io;
    return 0;
}
