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
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector col_sum(n, vector<long long>(n + 1));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                col_sum[j][i + 1] = col_sum[j][i] + grid[i][j];
            }
        }
        vector f(n, vector<array<long long, 2>>(n + 1));
        for (int j = 0; j < n - 1; j++) {
            long long pre_max = f[j][0][1] - col_sum[j][0];
            for (int pre = 1; pre <= n; pre++) {
                f[j + 1][pre][0] = f[j + 1][pre][1] = max(f[j][pre][0], pre_max + col_sum[j][pre]);
                pre_max = max(pre_max, f[j][pre][1] - col_sum[j][pre]);
            }
            long long suf_max = f[j][n][0] + col_sum[j + 1][n];
            for (int pre = n - 1; pre > 0; pre--) {
                f[j + 1][pre][0] = max(f[j + 1][pre][0], suf_max - col_sum[j + 1][pre]);
                suf_max = max(suf_max, f[j][pre][0] + col_sum[j + 1][pre]);
            }
            f[j + 1][0][0] = suf_max;
            f[j + 1][0][1] = max(f[j][0][0], f[j][n][0]);
        }
        long long ans = 0;
        for (auto& row : f[n - 1]) {
            ans = max(ans, row[0]);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}