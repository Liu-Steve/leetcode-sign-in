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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef pair<int, int> pr;
typedef pair<ll, ll> prl;
typedef vector<pr> vp;
typedef unordered_set<int> hm;
typedef unordered_map<ll, int> memory;

constexpr long long MOD = 1000000007LL;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector ans(m, vector<int>(n));
        auto f = [&](int x, int y, int val) -> void {
            int layer = min({x, y, m - 1 - x, n - 1 - y});
            int len = 2 * m + 2 * n - 4 - 8 * layer;
            int idx = -1;
            if (y == layer) {
                idx = x - layer;
            } else if (x == m - 1 - layer) {
                idx = m - 1 - 2 * layer + y - layer;
            } else if (y == n - 1 - layer) {
                idx = len / 2 + m - 1 - layer - x;
            } else if (x == layer) {
                idx = len - (y - layer);
            }
            idx = (idx + k) % len;
            int nx = -1;
            int ny = -1;
            if (idx < m - 2 * layer) {
                nx = layer + idx;
                ny = layer;
            } else if (idx < len / 2) {
                nx = m - 1 - layer;
                ny = layer + idx - (m - 2 * layer) + 1;
            } else if (idx < len / 2 + m - 2 * layer) {
                nx = m - 1 - layer - (idx - len / 2);
                ny = n - 1 - layer;
            } else if (idx < len) {
                nx = layer;
                ny = n - 1 - layer - (idx - (len / 2 + m - 2 * layer)) - 1;
            }
            ans[nx][ny] = val;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f(i, j, grid[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}