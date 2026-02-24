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
    string longestPalindrome(string s) {
        string t = "^";
        for (char ch : s) {
            t.push_back('#');
            t.push_back(ch);
        }
        t += "#$";
        int box_m = 0, box_r = 0, max_i = 0;
        vector<int> half_len(t.size());
        for (int i = 2; i < t.size(); ++i) {
            int hl = 1;
            if (i < box_r) {
                hl = min(half_len[box_m * 2 - i], box_r - i);
            }
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }
            half_len[i] = hl;
            if (hl > half_len[max_i]) {
                max_i = i;
            }
        }
        int hl = half_len[max_i];
        return s.substr((max_i - hl) / 2, hl - 1);
    }
};

int main() {
    io;
    return 0;
}