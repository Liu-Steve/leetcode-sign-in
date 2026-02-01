#include <bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int minCost(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(), [&](const auto &p1, const auto &p2) -> bool {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost = min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};

int main() {
    io;
    Solution s;
    return 0;
}