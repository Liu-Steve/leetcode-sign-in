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
typedef unordered_map<int, int> memory;

class Solution
{
public:
    ll findMaximumElegance(vv &items, int k)
    {
        sort(items.begin(), items.end(), greater<vi>());
        unordered_set<int> c;
        ll ans = 0;
        ll pro = 0;
        stack<int> st;
        for (int i = 0; i < items.size(); ++i)
        {
            if (i < k)
            {
                pro += items[i][0];
                if (c.count(items[i][1]) == 0)
                    c.insert(items[i][1]);
                else
                    st.push(items[i][0]);
            }
            else if (c.count(items[i][1]) == 0 && !st.empty())
            {
                pro += items[i][0] - st.top();
                st.pop();
                c.insert(items[i][1]);
            }
            ans = max(ans, pro + (ll)c.size() * (ll)c.size());
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
