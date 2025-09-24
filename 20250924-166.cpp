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
    string fractionToDecimal(long long numerator, long long denominator)
    {
        stringstream ss;
        if (numerator * denominator < 0)
            ss << '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        ss << numerator / denominator;
        if (numerator % denominator == 0)
            return ss.str();
        ss << '.';
        numerator %= denominator;
        string ans;
        unordered_map<long long, long long> mp;
        mp[numerator] = 0;
        while (numerator != 0)
        {
            numerator *= 10;
            ans.push_back(numerator / denominator + '0');
            numerator %= denominator;
            if (mp.count(numerator))
                break;
            mp[numerator] = ans.size();
        }
        if (numerator == 0)
        {
            ss << ans;
            return ss.str();
        }
        int re = mp[numerator];
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i == re)
                ss << '(';
            ss << ans[i];
        }
        ss << ')';
        return ss.str();
    }
};

int main()
{
    io;
    return 0;
}
