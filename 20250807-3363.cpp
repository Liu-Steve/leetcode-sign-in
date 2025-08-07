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
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int n = fruits.size();
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = max(n - i - 1, i + 1); j < n; ++j)
            {
                int num1 = (j - 1 >= max(n - i, i)) ? fruits[i - 1][j - 1] : -1;
                int num2 = (j >= max(n - i, i)) ? fruits[i - 1][j] : -1;
                int num3 = (j + 1 < n) ? fruits[i - 1][j + 1] : -1;
                fruits[i][j] += max(num1, max(num2, num3));
            }
        }
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = max(n - i - 1, i + 1); j < n; ++j)
            {
                int num1 = (j - 1 >= max(n - i, i)) ? fruits[j - 1][i - 1] : -1;
                int num2 = (j >= max(n - i, i)) ? fruits[j][i - 1] : -1;
                int num3 = (j + 1 < n) ? fruits[j + 1][i - 1] : -1;
                fruits[j][i] += max(num1, max(num2, num3));
            }
        }
        for (int i = 1; i < n; ++i)
            fruits[i][i] += fruits[i - 1][i - 1];
        return fruits[n - 1][n - 1] + fruits[n - 1][n - 2] + fruits[n - 2][n - 1];
    }
};

int main()
{
    io;
    return 0;
}
