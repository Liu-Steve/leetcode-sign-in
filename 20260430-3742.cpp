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
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp1(m + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(m + 1, vector<int>(n + 1, -1));
        dp2[0][1] = 0;
        for (int t = 0; t <= k; ++t) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 0) {
                        dp2[i + 1][j + 1] = max(dp1[i + 1][j + 1], max(dp2[i][j + 1], dp2[i + 1][j]));
                    } else {
                        dp2[i + 1][j + 1] = dp1[i + 1][j + 1];
                        if (dp1[i][j + 1] != -1) {
                            dp2[i + 1][j + 1] = max(dp2[i + 1][j + 1], dp1[i][j + 1] + grid[i][j]);
                        }
                        if (dp1[i + 1][j] != -1) {
                            dp2[i + 1][j + 1] = max(dp2[i + 1][j + 1], dp1[i + 1][j] + grid[i][j]);
                        }
                    }
                }
            }
            swap(dp1, dp2);
        }
        return dp1[m][n];
    }
};

int main() {
    io;
    return 0;
}