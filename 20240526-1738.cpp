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
private:
    int qs(vector<int> &nums, int l, int r, int k)
    {
        if (r - l == 1 && l == k)
            return nums[k];
        int pat = part(nums, l, r);
        if (pat <= k)
            return qs(nums, pat, r, k);
        else
            return qs(nums, l, pat, k);
    }

    int part(vector<int> &nums, int l, int r)
    {
        int idx = rand() % (r - l) + l;
        int cmp = nums[idx];
        swap(nums[idx], nums[r - 1]);
        int p1 = l;
        for (int i = l; i < r - 1; ++i)
        {
            bool eq = rand() % 2;
            if (nums[i] > cmp || (eq && nums[i] == cmp))
            {
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
        swap(nums[p1], nums[r - 1]);
        return p1;
    }

public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            int lst = 0;
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] ^= lst;
                lst = matrix[i][j];
            }
        }
        for (int j = 0; j < n; ++j)
        {
            int lst = 0;
            for (int i = 0; i < m; ++i)
            {
                matrix[i][j] ^= lst;
                lst = matrix[i][j];
            }
        }
        vector<int> val;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                val.push_back(matrix[i][j]);
        return qs(val, 0, m * n, k - 1);
    }
};

int main()
{
    io;
    return 0;
}
