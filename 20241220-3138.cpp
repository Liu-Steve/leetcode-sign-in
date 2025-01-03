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
    int minAnagramLength(string s)
    {
        int n = s.size();
        vector<vector<int>> pre(26, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 26; ++j)
                pre[j][i + 1] = pre[j][i] + (s[i] - 'a' == j);
        auto func = [&](int i) -> bool
        {
            for (int j = 0; j < 26; ++j)
            {
                int cnt = pre[j][i] - pre[j][0];
                for (int k = i; k < n; k += i)
                    if (pre[j][k + i] - pre[j][k] != cnt)
                        return false;
            }
            return true;
        };
        vector<int> len;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i != 0)
                continue;
            if (i * i != n)
                len.push_back(n / i);
            if (func(i))
                return i;
        }
        for (int i = len.size() - 1; i >= 0; --i)
            if (func(len[i]))
                return len[i];
        return n;
    }
};

int main()
{
    io;
    return 0;
}