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
    vector<vector<int>> rotate(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector b(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for (auto& row : grid) {
            for (int x : row) {
                total += x;
            }
        }
        auto check = [&](vector<vector<int>> a) -> bool {
            int m = a.size(), n = a[0].size();
            auto f = [&]() -> bool {
                unordered_set<long long> st = {0};
                long long s = 0;
                for (int i = 0; i < m - 1; i++) {
                    auto& row = a[i];
                    for (int j = 0; j < n; j++) {
                        int x = row[j];
                        s += x;
                        if (i > 0 || j == 0 || j == n - 1) {
                            st.insert(x);
                        }
                    }
                    if (n == 1) {
                        if (s * 2 == total || s * 2 - total == a[0][0] || s * 2 - total == row[0]) {
                            return true;
                        }
                        continue;
                    }
                    if (st.count(s * 2 - total)) {
                        return true;
                    }
                    if (i == 0) {
                        for (int x : row) {
                            st.insert(x);
                        }
                    }
                }
                return false;
            };
            if (f()) {
                return true;
            }
            reverse(a.begin(), a.end());
            return f();
        };
        return check(grid) || check(rotate(grid));
    }
};

int main() {
    io;
    return 0;
}