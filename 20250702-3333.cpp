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
    int possibleStringCount(string word, int k)
    {
        int n = word.size();
        if (k > n)
            return 0;
        vector<int> cnt;
        int p = 0;
        long long all = 1;
        k--;
        for (int i = 0; i <= n; ++i)
        {
            if (i < n && word[i] == word[p])
                continue;
            cnt.push_back(i - p - 1);
            all *= i - p;
            all %= MOD;
            k--;
            p = i;
        }
        if (k < 0)
            return all;

        int m = cnt.size();
        vector<int> dp1(k + 1), dp2(k + 1);
        for (int i = 0; i <= cnt[0] && i <= k; ++i)
            dp1[i] = 1;
        for (int i = 1; i < m; ++i)
        {
            long long sum = 0;
            for (int j = 0; j <= k; ++j)
            {
                sum += dp1[j];
                if (j - cnt[i] - 1 >= 0)
                    sum += MOD - dp1[j - cnt[i] - 1];
                sum %= MOD;
                dp2[j] = sum;
            }
            swap(dp1, dp2);
        }
        long long sum = 0;
        for (int num : dp1)
            sum += num;
        return (all + MOD - sum % MOD) % MOD;
    }
};

int main()
{
    io;
    return 0;
}
