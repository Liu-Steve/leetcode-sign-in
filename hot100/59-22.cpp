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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string par;
        int diff = 0;
        int left = n;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == 2 * n) {
                ans.push_back(par);
                return;
            }
            if (left != 0) {
                par.push_back('(');
                diff++;
                left--;
                dfs(i + 1);
                par.pop_back();
                diff--;
                left++;
            }
            if (diff != 0) {
                par.push_back(')');
                diff--;
                dfs(i + 1);
                diff++;
                par.pop_back();
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