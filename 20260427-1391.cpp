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
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<bool> L{0, 1, 0, 0, 1, 0, 1};
        vector<bool> R{0, 1, 0, 1, 0, 1, 0};
        vector<bool> U{0, 0, 1, 1, 1, 0, 0};
        vector<bool> P{0, 0, 1, 0, 0, 1, 1};
        int m = grid.size();
        int n = grid[0].size();
        vector vis(m, vector(n, false));
        vector<int> bias{0, -1, 0, 1, 0};
        auto dfs = [&](auto&& dfs, int x, int y, int lst, int type) -> bool {
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
                return false;
            }
            if (type == 0) {
                if (!L[grid[x][y]] || !R[lst]) {
                    return false;
                }
            } else if (type == 1) {
                if (!U[grid[x][y]] || !P[lst]) {
                    return false;
                }
            } else if (type == 2) {
                if (!L[lst] || !R[grid[x][y]]) {
                    return false;
                }
            } else if (type == 3) {
                if (!U[lst] || !P[grid[x][y]]) {
                    return false;
                }
            }
            vis[x][y] = 1;
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x + bias[i];
                int ny = y + bias[i + 1];
                if (dfs(dfs, nx, ny, grid[x][y], i)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(dfs, 0, 0, 0, -1);
    }
};

int main() {
    io;
    return 0;
}