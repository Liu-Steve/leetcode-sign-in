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
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        function<void(int)> update = [&](int num) {
            auto it = lower_bound(ans.begin(), ans.end(), num, std::greater<int>());
            if (it != ans.end() && *it == num) {
                return;
            }
            ans.insert(it, num);
            if (ans.size() > 3) {
                ans.pop_back();
            }
        };
        int m = grid.size();
        int n = grid[0].size();
        vector add(m + 1, vector<int>(n + 1));
        vector minus(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                add[i + 1][j + 1] = add[i][j] + grid[i][j];
                minus[i + 1][j] = minus[i][j + 1] + grid[i][j];
                update(grid[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 1;; ++k) {
                    if (i + 2 * k >= m || j - k < 0 || j + k >= n) {
                        break;
                    }
                    int sum = 0;
                    sum += add[i + k + 1][j + k + 1] - add[i][j];
                    sum += add[i + 2 * k + 1][j + 1] - add[i + k][j - k];
                    sum += minus[i + k + 1][j - k] - minus[i][j + 1];
                    sum += minus[i + 2 * k + 1][j] - minus[i + k][j + k + 1];
                    sum -= grid[i][j] + grid[i + k][j + k] + grid[i + k][j - k] + grid[i + 2 * k][j];
                    update(sum);
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