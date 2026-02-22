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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) {
            return false;
        } else if (target == matrix[0][0]) {
            return true;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return false;
    }
};

int main() {
    io;
    return 0;
}