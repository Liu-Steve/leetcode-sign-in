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
    int countSpecialNumbers(int n)
    {
        string s = to_string(n);
        int d = s.size();
        auto p = [](int m, int k) -> int
        {
            int ans = 1;
            while (k--)
                ans *= m--;
            return ans;
        };
        int ret = 0;
        for (int i = 1; i < d; ++i)
            ret += 9 * p(9, i - 1);
        int used = 0;
        bool unique = true;
        for (int i = d - 1; i >= 0; --i)
        {
            int up = s[d - i - 1] - '0';
            for (int j = (i == (d - 1) ? 1 : 0); j < up; ++j)
            {
                if (used & (1 << j))
                    continue;
                ret += p(10 - (d - i), i);
            }
            if (used & (1 << up))
            {
                unique = false;
                break;
            }
            used |= (1 << up);
        }
        if (unique)
            ret += 1;
        return ret;
    }
};

int main()
{
    io;
    return 0;
}
