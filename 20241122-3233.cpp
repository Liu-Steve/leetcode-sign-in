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
    int nonSpecialCount(int l, int r)
    {
        int n = 40000;
        int ans = 0;
        vector<int> pri;
        vector<uint8_t> not_prime(n + 1); // bool
        not_prime[0] = true;
        not_prime[1] = true;
        for (int i = 2; i <= n; ++i)
        {
            if (!not_prime[i])
            {
                pri.push_back(i);
                if (i * i >= l && i * i <= r)
                    ans++;
            }
            for (int pri_j : pri)
            {
                if (pri_j * i > n)
                    break;
                not_prime[pri_j * i] = true;
                if (i % pri_j == 0)
                    break;
            }
        }
        return r - l + 1 - ans;
    }
};

int main()
{
    io;
    return 0;
}
