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
    string findLexSmallestString(string s, int a, int b)
    {
        int n = s.size();
        string res = s;
        s = s + s;
        int g = gcd(b, n);
        int add_cnt = a * 10 / gcd(a, 10);
        auto add = [&](string &t, int start)
        {
            int minVal = 10, times = 0;
            for (int i = 0; i < add_cnt; i++)
            {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal)
                {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < n; i += 2)
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
        };
        for (int i = 0; i < n; i += g)
        {
            string t = s.substr(i, n);
            add(t, 1);
            if (b % 2)
                add(t, 0);
            res = min(res, t);
        }
        return res;
    }
};

int main()
{
    io;
    return 0;
}
