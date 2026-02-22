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
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector vis(m, vector<uint8_t>(n, 0));
        vector<int> bias{0, -1, 0, 1, 0};
        function<bool(int, int, int)> dfs = [&](int x, int y, int i) -> bool {
            if (i == word.size()) {
                return true;
            }
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || board[x][y] != word[i]) {
                return false;
            }
            vis[x][y] = 1;
            for (int j = 0; j < 4; ++j) {
                if (dfs(x + bias[j], y + bias[j + 1], i + 1)) {
                    return true;
                }
            }
            vis[x][y] = 0;
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    io;
    return 0;
}