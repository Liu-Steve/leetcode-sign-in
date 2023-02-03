#include "bits/stdc++.h"
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef pair<int, int> pr;
typedef vector<pr> vp;

const ll MOD = 1000000007;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int xval;

    TreeNode *findX(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == xval)
            return root;
        TreeNode *temp = findX(root->left);
        if (temp != nullptr)
            return temp;
        return findX(root->right);
    }

    int cntNode(TreeNode *root, int num)
    {
        if (root == nullptr)
            return num;
        num++;
        num = cntNode(root->left, num);
        num = cntNode(root->right, num);
        return num;
    }

    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        xval = x;
        TreeNode *nodeN = findX(root);
        int cntl = cntNode(nodeN->left, 0);
        int cntr = cntNode(nodeN->right, 0);
        int cntt = n - 1 - cntl - cntr;
        return (cntl > n / 2) || (cntr > n / 2) || (cntt > n / 2);
    }
};

int main()
{
    io;
    Solution s;
    TreeNode *t1 = new TreeNode(
        1,
        new TreeNode(
            2,
            new TreeNode(
                4,
                new TreeNode(8),
                new TreeNode(9)),
            new TreeNode(
                5,
                new TreeNode(10),
                new TreeNode(11))),
        new TreeNode(
            3,
            new TreeNode(6),
            new TreeNode(7)));
    cout << s.btreeGameWinningMove(t1, 11, 3) << endl;
    return 0;
}