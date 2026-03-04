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
    unordered_map<int, int> mem;

public:
    int numSquares(int n) {
        if (mem.count(n)) {
            return mem[n];
        }
        int ans = n;
        for (int i = 1; i * i <= n; ++i) {
            if (i * i == n) {
                mem[n] = 1;
                return 1;
            }
            ans = min(ans, numSquares(n - i * i) + 1);
        }
        mem[n] = ans;
        return ans;
    }
};

int main() {
    io;
    return 0;
}