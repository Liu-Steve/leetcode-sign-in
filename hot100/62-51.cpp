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
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<int> plus(2 * n - 1);
        vector<int> minus(2 * n - 1);
        vector<int> seq;
        vector<vector<string>> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back();
                for (int i = 0; i < n; ++i) {
                    ans.back().emplace_back();
                    for (int j = 0; j < n; ++j) {
                        if (j == seq[i]) {
                            ans.back().back().push_back('Q');
                        } else {
                            ans.back().back().push_back('.');
                        }
                    }
                }
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (col[j] || plus[i + j] || minus[i - j + n - 1]) {
                    continue;
                }
                col[j] = 1;
                plus[i + j] = 1;
                minus[i - j + n - 1] = 1;
                seq.push_back(j);
                dfs(i + 1);
                col[j] = 0;
                plus[i + j] = 0;
                minus[i - j + n - 1] = 0;
                seq.pop_back();
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