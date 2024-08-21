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
typedef unordered_map<ll, int> memory;

class Solution
{
public:
    long long findMaximumNumber(long long k, int x)
    {
        auto acc = [=](long long num) -> long long
        {
            int i = x - 1;
            long long ans = 0;
            while (i < 61)
            {
                long long power2 = (1ll << i);
                ans += num / (2 * power2) * power2 + max(0ll, (num % (2 * power2) - power2 + 1));
                i += x;
            }
            return ans;
        };
        long long l = 0;
        long long r = 1e15;
        while (r - l > 1)
        {
            long long mid = (l + r) / 2;
            long long sum = acc(mid);
            if (sum <= k)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    io;
    return 0;
}
