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
    long long kMirror(int k, int n)
    {
        vector<int> digit(100);
        auto isPalindrome = [&](long long x) -> bool
        {
            int length = -1;
            while (x)
            {
                ++length;
                digit[length] = x % k;
                x /= k;
            }
            for (int i = 0, j = length; i < j; ++i, --j)
                if (digit[i] != digit[j])
                    return false;
            return true;
        };
        int left = 1, count = 0;
        long long ans = 0;
        while (count < n)
        {
            int right = left * 10;
            for (int op = 0; op < 2; ++op)
            {
                for (int i = left; i < right && count < n; ++i)
                {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x)
                    {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined))
                    {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
