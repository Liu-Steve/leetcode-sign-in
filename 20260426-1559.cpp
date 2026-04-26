#include <bits/stdc++.h>

#include <vector>
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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector sta(m, vector<int>(n));
        vector<int> bias{0, -1, 0, 1, 0};
        auto dfs = [&](auto&& dfs, int x, int y, char target, int fa) -> bool {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != target) {
                return false;
            }
            if (sta[x][y] == 2) {
                return true;
            }
            sta[x][y] = 2;
            for (int i = 0; i < 4; ++i) {
                if (i - fa == 2 || i - fa == -2) {
                    continue;
                }
                int nx = x + bias[i];
                int ny = y + bias[i + 1];
                if (dfs(dfs, nx, ny, target, i)) {
                    return true;
                }
            }
            sta[x][y] = 1;
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sta[i][j]) {
                    continue;
                }
                if (dfs(dfs, i, j, grid[i][j], 100)) {
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