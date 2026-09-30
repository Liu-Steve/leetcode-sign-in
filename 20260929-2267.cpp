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
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        vector vis(m, vector(n, vector<int8_t>((m + n + 1) / 2)));
        auto dfs = [&](auto&& dfs, int x, int y, int c) -> bool {
            if (c > m - x + n - y - 1) {
                return false;
            }
            if (x == m - 1 && y == n - 1) {
                return c == 1;
            }
            if (vis[x][y][c]) {
                return false;
            }
            vis[x][y][c] = true;
            c += grid[x][y] == '(' ? 1 : -1;
            if (c < 0) {
                return false;
            }
            return x < m - 1 && dfs(dfs, x + 1, y, c) || y < n - 1 && dfs(dfs, x, y + 1, c);
        };
        return dfs(dfs, 0, 0, 0);
    }
};

int main() {
    io;
    return 0;
}