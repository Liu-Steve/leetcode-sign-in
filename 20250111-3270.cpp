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
    int generateKey(int num1, int num2, int num3)
    {
        int ans = min(min((num1 % 10), (num2 % 10)), (num3 % 10));
        num1 /= 10;
        num2 /= 10;
        num3 /= 10;
        ans += min(min((num1 % 10), (num2 % 10)), (num3 % 10)) * 10;
        num1 /= 10;
        num2 /= 10;
        num3 /= 10;
        ans += min(min((num1 % 10), (num2 % 10)), (num3 % 10)) * 100;
        num1 /= 10;
        num2 /= 10;
        num3 /= 10;
        ans += min(min((num1 % 10), (num2 % 10)), (num3 % 10)) * 1000;
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
