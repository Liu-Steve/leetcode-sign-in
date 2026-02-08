#include <bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

constexpr long long MOD = 1000000007LL;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) {
            idx[inorder[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int p, int l, int r) -> TreeNode* {
            if (l >= r) {
                return nullptr;
            }
            int m = idx[preorder[p]];
            TreeNode* node = new TreeNode(preorder[p]);
            node->left = dfs(p + 1, l, m);
            node->right = dfs(p + m - l + 1, m + 1, r);
            return node;
        };
        return dfs(0, 0, n);
    }
};

int main() {
    io;
    return 0;
}