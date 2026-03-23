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
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector top(m, vector<long long>(n, grid[0][0]));
        vector bottom(m, vector<long long>(n, grid[0][0]));
        for (int i = 1; i < n; ++i) {
            top[0][i] = bottom[0][i] = grid[0][i] * top[0][i - 1];
        }
        for (int i = 1; i < m; ++i) {
            top[i][0] = bottom[i][0] = grid[i][0] * top[i - 1][0];
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    top[i][j] = max(top[i - 1][j], top[i][j - 1]) * grid[i][j];
                    bottom[i][j] = min(bottom[i - 1][j], bottom[i][j - 1]) * grid[i][j];
                } else {
                    bottom[i][j] = max(top[i - 1][j], top[i][j - 1]) * grid[i][j];
                    top[i][j] = min(bottom[i - 1][j], bottom[i][j - 1]) * grid[i][j];
                }
            }
        }
        return top[m - 1][n - 1] < 0 ? -1 : top[m - 1][n - 1] % MOD;
    }
};

int main() {
    io;
    return 0;
}