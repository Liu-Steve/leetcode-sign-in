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
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        int num = 0;
        for (char ch : version1)
            if (ch == '.')
            {
                v1.push_back(num);
                num = 0;
            }
            else
                num = num * 10 + (ch - '0');
        v1.push_back(num);
        num = 0;
        for (char ch : version2)
            if (ch == '.')
            {
                v2.push_back(num);
                num = 0;
            }
            else
                num = num * 10 + (ch - '0');
        v2.push_back(num);
        int len = max(v1.size(), v2.size());
        while (v1.size() < len)
            v1.push_back(0);
        while (v2.size() < len)
            v2.push_back(0);
        for (int i = 0; i < len; ++i)
            if (v1[i] < v2[i])
                return -1;
            else if (v1[i] > v2[i])
                return 1;
        return 0;
    }
};

int main()
{
    io;
    return 0;
}
