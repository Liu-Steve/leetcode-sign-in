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
private:
    int findMinIndex(vector<int>& nums) {
        if (nums.front() <= nums.back()) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[l]) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

public:
    int search(vector<int>& nums, int target) {
        int idx = findMinIndex(nums);
        if (target < nums[idx]) {
            return -1;
        } else if (target == nums[idx]) {
            return idx;
        }
        int n = nums.size();
        int l = 0;
        int r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (nums[(m + idx) % n] == target) {
                return (m + idx) % n;
            } else if (nums[(m + idx) % n] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        return -1;
    }
};

int main() {
    io;
    return 0;
}