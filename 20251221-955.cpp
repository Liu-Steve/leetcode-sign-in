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
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<pair<int, int>> range{{0, n - 1}};
        for (int i = 0; i < m; ++i)
        {
            vector<pair<int, int>> new_range;
            bool valid = true;
            for (auto [l, r] : range)
            {
                char lst = 'a' - 1;
                int new_l = l;
                int new_r = l;
                for (int j = l; j <= r; ++j)
                {
                    if (strs[j][i] < lst)
                    {
                        valid = false;
                        break;
                    }
                    else if (strs[j][i] == lst)
                        new_r = j;
                    else
                    {
                        if (new_l != new_r)
                            new_range.emplace_back(new_l, new_r);
                        new_l = new_r = j;
                    }
                    lst = strs[j][i];
                }
                if (!valid)
                    break;
                if (new_l != new_r)
                    new_range.emplace_back(new_l, new_r);
            }
            if (!valid)
            {
                ans++;
                continue;
            }
            if (new_range.empty())
                break;
            range = new_range;
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
