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
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [&](vector<int> &e1, vector<int> &e2)
             {if (e1[1] == e2[1]) 
                return e1[2] > e2[2]; 
                return e1[1] < e2[1]; });
        vector<pair<int, int>> st{{0, 0}};
        int ans = 0;
        for (auto &e : events)
        {
            int l = 0;
            int r = st.size();
            while (l + 1 < r)
            {
                int m = (l + r) / 2;
                if (st[m].first < e[0])
                    l = m;
                else
                    r = m;
            }
            ans = max(ans, st[l].second + e[2]);
            if (st.back().second < e[2])
                st.emplace_back(e[1], e[2]);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
