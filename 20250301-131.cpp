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
    vector<vector<string>> partition(string s)
    {
        auto isValid = [&](string &str) -> bool
        {
            int n = str.size();
            for (int i = 0; i < n - 1 - i; ++i)
                if (str[i] != str[n - 1 - i])
                    return false;
            return true;
        };
        int n = s.size();
        vector<vector<string>> ans;
        for (int i = 0; i < (1 << (n - 1)); ++i)
        {
            vector<string> v;
            string str(1, s[0]);
            bool b = false;
            for (int j = 0; j < n - 1; ++j)
            {
                if (i & (1 << j))
                {
                    str.push_back(s[j + 1]);
                    continue;
                }
                if (!isValid(str))
                {
                    b = true;
                    break;
                }
                v.push_back(str);
                str = string(1, s[j + 1]);
            }
            if (b || !isValid(str))
                continue;
            v.push_back(str);
            ans.emplace_back(v);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
