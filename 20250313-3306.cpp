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
    long long count(string &word, int k)
    {
        int n = word.size();
        long long ans = 0;
        int l = 0;
        int other = 0;
        vector<int> c(26);
        vector<bool> v(26, false);
        v['a' - 'a'] = true;
        v['e' - 'a'] = true;
        v['i' - 'a'] = true;
        v['o' - 'a'] = true;
        v['u' - 'a'] = true;
        auto f = [&]() -> bool
        {
            return c['a' - 'a'] > 0 &&
                   c['e' - 'a'] > 0 &&
                   c['i' - 'a'] > 0 &&
                   c['o' - 'a'] > 0 &&
                   c['u' - 'a'] > 0;
        };
        for (int j = 0; j < n; ++j)
        {
            c[word[j] - 'a']++;
            if (!v[word[j] - 'a'])
                other++;
            while (f() && other >= k)
            {
                c[word[l] - 'a']--;
                if (!v[word[l] - 'a'])
                    other--;
                l++;
            }
            ans += l;
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k)
    {
        return count(word, k) - count(word, k + 1);
    }
};

int main()
{
    io;
    return 0;
}
