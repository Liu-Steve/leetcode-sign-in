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
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        unordered_map<char, vector<char>> letter{
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
        string st;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(st);
                return;
            }
            for (char ch : letter[digits[i]]) {
                st.push_back(ch);
                dfs(i + 1);
                st.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {
    io;
    return 0;
}