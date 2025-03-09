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
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end(), [&](vector<int> a, vector<int> b) -> bool
             {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1]; });
        vector<pair<int, int>> st;
        st.emplace_back(0, 0);
        for (auto &i : items)
        {
            if (i[1] <= st.back().second)
                continue;
            st.emplace_back(i[0], i[1]);
        }
        auto find = [&](int q) -> int
        {
            int l = 0;
            int r = st.size();
            while (l + 1 < r)
            {
                int m = (l + r) / 2;
                if (st[m].first <= q)
                    l = m;
                else
                    r = m;
            }
            return st[l].second;
        };
        vector<int> ans;
        for (int q : queries)
            ans.push_back(find(q));
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
