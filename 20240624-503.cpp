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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int it = max_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        vector<int> ans(n);
        vector<int> st;
        ans[it] = -1;
        st.push_back(nums[it]);
        for (int i = it - 1; (i + n) % n != it; --i)
        {
            if (i < 0)
                i = n - 1;
            while (!st.empty() && nums[i] >= st.back())
                st.pop_back();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.back();
            st.push_back(nums[i]);
        }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
