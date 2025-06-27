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
    void permuteFunc(const string &nums, auto &&f)
    {
        int n = nums.size();
        string path;
        vector<int8_t> on_path(n);
        auto dfs = [&](this auto &&dfs) -> void
        {
            f(path);
            if (path.size() == n)
                return;
            for (int j = 0; j < n; j++)
            {
                if (on_path[j] || j > 0 && nums[j] == nums[j - 1] && !on_path[j - 1])
                    continue;
                path.push_back(nums[j]);
                on_path[j] = true;
                dfs();
                on_path[j] = false;
                path.pop_back();
            }
        };
        dfs();
    };

    bool isSubsequence(const string &seq, int k, const string &s)
    {
        int n = seq.size();
        int i = 0;
        for (char c : s)
            if (seq[i % n] == c)
            {
                i++;
                if (i == n * k)
                    return true;
            }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        int cnt[26]{};
        for (char c : s)
            cnt[c - 'a']++;
        string a;
        for (int i = 25; i >= 0; i--)
            a.insert(a.end(), cnt[i] / k, 'a' + i);
        string ans;
        permuteFunc(a, [&](const string &seq)
                    {if ((seq.size() > ans.size() || 
            seq.size() == ans.size() && seq > ans) && 
            isSubsequence(seq, k, s))
                ans = seq; });
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
