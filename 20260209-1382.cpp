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

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        function<void(TreeNode*)> func = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            func(node->left);
            nums.push_back(node->val);
            func(node->right);
        };
        func(root);
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
            if (l >= r) {
                return nullptr;
            }
            int m = (l + r) / 2;
            TreeNode* ans = new TreeNode(nums[m]);
            if (l + 1 == r) {
                return ans;
            }
            ans->left = dfs(l, m);
            ans->right = dfs(m + 1, r);
            return ans;
        };
        return dfs(0, nums.size());
    }
};

int main() {
    io;
    Solution s;
    return 0;
}