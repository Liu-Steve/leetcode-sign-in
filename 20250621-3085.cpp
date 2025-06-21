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
    int minimumDeletions(string word, int k)
    {
        vector<int> cnt(26);
        for (char ch : word)
            cnt[ch - 'a']++;
        sort(cnt.begin(), cnt.end());
        int ans = INT32_MAX;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] == 0)
                continue;
            int l = cnt[i];
            int r = cnt[i] + k;
            int num = 0;
            for (int c : cnt)
            {
                if (l <= c && c <= r)
                    continue;
                else if (c < l)
                    num += c;
                else
                    num += c - r;
            }
            ans = min(ans, num);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
