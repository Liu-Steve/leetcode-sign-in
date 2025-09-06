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
    long long minOperations(vector<vector<int>> &queries)
    {
        vector<long long> sp;
        for (int i = 0; i <= 40; i += 2)
            sp.push_back((1ll << i) - 1);
        long long ans = 0;
        for (auto &q : queries)
        {
            long long l = q[0];
            long long r = q[1];
            long long sum = 0;
            for (int i = 0; i < sp.size(); ++i)
            {
                if (sp[i] < l)
                    continue;
                if (sp[i] >= r)
                {
                    if (sp[i - 1] < l)
                        sum += (r - l + 1) * i;
                    else
                        sum += (r - sp[i - 1]) * i;
                    break;
                }
                if (sp[i] >= l && sp[i - 1] < l)
                    sum += (sp[i] - l + 1) * i;
                else
                    sum += (sp[i] - sp[i - 1]) * i;
            }
            ans += (sum + (sum & 1)) / 2;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
