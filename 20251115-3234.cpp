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
    int numberOfSubstrings(string s)
    {
        int ans = 0;
        int total1 = 0;
        int n = s.size();
        vector<int> zero;
        zero.push_back(-1);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                zero.push_back(i);
            else
            {
                total1++;
                ans += i - zero.back();
            }
            int cnt0 = 0;
            for (auto it = zero.rbegin(); *it != -1; ++it)
            {
                int idx = *it;
                int idx_front = *(it + 1);
                cnt0++;
                if (cnt0 * cnt0 > total1)
                    break;
                int cnt1 = i - idx + 1 - cnt0;
                ans += max(idx - max(cnt0 * cnt0 - cnt1, 0) - idx_front, 0);
            }
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
