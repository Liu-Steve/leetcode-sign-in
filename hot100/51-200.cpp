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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> bias{0, 1, 0, -1, 0};
        function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = -1;
            for (int d = 0; d < 4; ++d) {
                if (x + bias[d] < 0 || x + bias[d] >= m || y + bias[d + 1] < 0 || y + bias[d + 1] >= n) {
                    continue;
                }
                if (grid[x + bias[d]][y + bias[d + 1]] == '1') {
                    dfs(x + bias[d], y + bias[d + 1]);
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}