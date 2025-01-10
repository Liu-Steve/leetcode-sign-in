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
    long long validSubstringCount(string word1, string word2)
    {
        long long ans = 0;
        vector<int> cnt1(26), cnt2(26);
        for (char ch : word2)
            cnt2[ch - 'a']++;
        int l = 0;
        int valid = 0;
        for (int i = 0; i < 26; ++i)
            if (cnt2[i] == 0)
                valid++;
        int i = 0;
        for (; i < word1.size(); ++i)
        {
            if (cnt1[word1[i] - 'a'] == cnt2[word1[i] - 'a'] - 1)
                valid++;
            if (valid == 26)
                break;
            cnt1[word1[i] - 'a']++;
        }
        if (valid < 26)
            return ans;
        for (; i < word1.size(); ++i)
        {
            cnt1[word1[i] - 'a']++;
            while (cnt1[word1[l] - 'a'] > cnt2[word1[l] - 'a'])
            {
                cnt1[word1[l] - 'a']--;
                l++;
            }
            ans += l + 1;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
