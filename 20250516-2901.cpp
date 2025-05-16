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
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<pair<int, int>> dp;
        int max_cnt = 0;
        int max_p = -1;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            int p = -1;
            for (int j = 0; j < i; ++j)
            {
                if (groups[j] == groups[i])
                    continue;
                if (words[j].size() != words[i].size())
                    continue;
                int diff = 0;
                for (int k = 0; k < words[j].size(); ++k)
                    diff += (words[j][k] != words[i][k]);
                if (diff != 1)
                    continue;
                if (dp[j].first <= cnt)
                    continue;
                cnt = dp[j].first;
                p = j;
            }
            dp.emplace_back(cnt + 1, p);
            if (dp.back().first > max_cnt)
            {
                max_cnt = cnt + 1;
                max_p = i;
            }
        }
        vector<string> ans(max_cnt);
        while (max_p != -1)
        {
            ans[max_cnt - 1] = words[max_p];
            max_cnt--;
            max_p = dp[max_p].second;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
