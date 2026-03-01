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
    void sp(int l, int r, vector<int>& nums, int target) {
        if (l >= r) {
            return;
        }
        int t = rand() % (r - l + 1) + l;
        swap(nums[l], nums[t]);
        t = l;
        int k = r;
        while (t < k) {
            if (nums[t + 1] > nums[t] || (nums[t + 1] == nums[t] && rand() % 2)) {
                swap(nums[t + 1], nums[t]);
                t++;
            } else {
                swap(nums[t + 1], nums[k]);
                k--;
            }
        }
        if (t == target) {
            return;
        }
        if (t > target)
            sp(l, t - 1, nums, target);
        else
            sp(t + 1, r, nums, target);
    }

    int findKthLargest(vector<int>& nums, int k) {
        sp(0, nums.size() - 1, nums, k - 1);
        return nums[k - 1];
    }
};

int main() {
    io;
    return 0;
}