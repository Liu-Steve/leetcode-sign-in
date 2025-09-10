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
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int m = languages.size();
        vector<set<int>> languageSet;
        for (auto &l : languages)
            languageSet.emplace_back(l.begin(), l.end());
        vector<bool> needHelp(m);
        for (auto &f : friendships)
        {
            set<int> &u = languageSet[f[0] - 1];
            set<int> &v = languageSet[f[1] - 1];
            bool find = false;
            for (int ele : u)
                if (v.count(ele))
                {
                    find = true;
                    break;
                }
            if (find)
                continue;
            needHelp[f[0] - 1] = true;
            needHelp[f[1] - 1] = true;
        }
        int ans = m;
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < m; ++j)
                if (!languageSet[j].count(i) && needHelp[j])
                    cnt++;
            ans = min(ans, cnt);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
