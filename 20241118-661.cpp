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
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(img);
        vector<int> b{0, 1, 1, -1, 0, -1, -1, 1, 0};
        auto valid = [=](int x, int y) -> bool
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int sum = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; ++k)
                    if (valid(i + b[k], j + b[k + 1]))
                    {
                        sum += img[i + b[k]][j + b[k + 1]];
                        cnt++;
                    }
                ans[i][j] = sum / cnt;
            }
        return ans;
    }
};

int main()
{
    io;
    return 0;
}
