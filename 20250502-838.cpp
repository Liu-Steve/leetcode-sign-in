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
#define MAX_N 10000
#define MAX_E 13

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
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        string ans(dominoes);
        int l = -1;
        char l_ch = 'L';
        int r = -1;
        char r_ch = 'L';
        for (int i = 0; i < n; ++i)
        {
            if (i >= r)
            {
                r = i + 1;
                while (r < n && dominoes[r] == '.')
                    r++;
                r_ch = (r == n ? 'R' : dominoes[r]);
            }
            if (dominoes[i] != '.')
            {
                l = i;
                l_ch = dominoes[i];
                continue;
            }
            if (l_ch == 'L' && r_ch == 'R')
                continue;
            if (l_ch == 'R' && r_ch == 'R')
            {
                ans[i] = 'R';
                continue;
            }
            if (l_ch == 'L' && r_ch == 'L')
            {
                ans[i] = 'L';
                continue;
            }
            if (i - l == r - i)
                continue;
            ans[i] = (i - l < r - i ? 'R' : 'L');
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
