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
    long long countGoodIntegers(int n, int k)
    {
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = factorial[i - 1] * i;
        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);
        for (int i = base; i < base * 10; ++i)
        {
            string s = to_string(i);
            s += string(s.rbegin() + (n % 2), s.rend());
            if (stoll(s) % k)
                continue;
            sort(s.begin(), s.end());
            if (!vis.insert(s).second)
                continue;
            vector<int> cnt(10);
            for (char ch : s)
                cnt[ch - '0']++;
            int res = (n - cnt[0]) * factorial[n - 1];
            for (int c : cnt)
                res /= factorial[c];
            ans += res;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
