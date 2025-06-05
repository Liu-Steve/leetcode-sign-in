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
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector mp(26, vector<int>(26));
        for (int i = 0; i < 26; ++i)
            mp[i][i] = 1;
        for (int i = 0; i < s1.size(); ++i)
        {
            mp[s1[i] - 'a'][s2[i] - 'a'] = 1;
            mp[s2[i] - 'a'][s1[i] - 'a'] = 1;
        }
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    if (mp[i][k] && mp[k][j])
                        mp[i][j] = 1;
        vector<int> v(26);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                if (mp[i][j])
                {
                    v[i] = j;
                    break;
                }
        for (char &ch : baseStr)
            ch = v[ch - 'a'] + 'a';
        return baseStr;
    }
};

int main()
{
    io;
    return 0;
}
