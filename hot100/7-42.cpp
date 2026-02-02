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
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = max(pre[i], height[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = max(suf[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int surface = min(pre[i + 1], suf[i]);
            ans += max(0, surface - height[i]);
        }
        return ans;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}