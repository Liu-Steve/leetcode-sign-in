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
    int getK(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (true) {
            if (idx1 == m) {
                return nums2[idx2 + k - 1];
            }
            if (idx2 == n) {
                return nums1[idx1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[idx1], nums2[idx2]);
            }
            int newIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, n - 1);
            if (nums1[newIdx1] <= nums2[newIdx2]) {
                k -= newIdx1 - idx1 + 1;
                idx1 = newIdx1 + 1;
            } else {
                k -= newIdx2 - idx2 + 1;
                idx2 = newIdx2 + 1;
            }
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2 == 1) {
            return getK(nums1, nums2, (sum + 1) / 2);
        } else {
            return (getK(nums1, nums2, sum / 2) + getK(nums1, nums2, sum / 2 + 1)) / 2.0;
        }
    }
};

int main() {
    io;
    return 0;
}