#include <bits/stdc++.h>

#include <unordered_map>
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

template <typename T>
class FenwickTree {
    vector<T> tree;

public:
    FenwickTree(int n) : tree(n + 1) {}

    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] ^= val;
        }
    }

    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res ^= tree[i];
        }
        return res;
    }
};

class LcaBinaryLifting {
    vector<int> depth;
    vector<vector<int>> pa;

public:
    vector<int> tin;
    vector<int> tout;
    vector<int> path_xor_from_root;

    LcaBinaryLifting(vector<vector<int>>& edges, string& s) {
        int n = edges.size() + 1;
        int m = __bit_width((uint32_t)n);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        depth.resize(n);
        pa.resize(m, vector<int>(n, -1));
        tin.resize(n);
        tout.resize(n);
        path_xor_from_root.resize(n);
        path_xor_from_root[0] = 1 << (s[0] - 'a');
        int clock = 0;
        auto dfs = [&](auto&& dfs, int x, int fa) -> void {
            pa[0][x] = fa;
            tin[x] = ++clock;
            for (int y : g[x]) {
                if (y != fa) {
                    depth[y] = depth[x] + 1;
                    path_xor_from_root[y] = path_xor_from_root[x] ^ (1 << (s[y] - 'a'));
                    dfs(dfs, y, x);
                }
            }
            tout[x] = clock;
        };
        dfs(dfs, 0, -1);
        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                if (int p = pa[i][x]; p != -1) {
                    pa[i + 1][x] = pa[i][p];
                }
            }
        }
    }

    int get_kth_ancestor(int node, int k) {
        for (; k > 0 && node >= 0; k &= k - 1) {
            node = pa[__countr_zero((uint32_t)k)][node];
        }
        return node;
    }

    int get_lca(int x, int y) {
        if (depth[x] > depth[y]) {
            swap(x, y);
        }
        y = get_kth_ancestor(y, depth[y] - depth[x]);
        if (y == x) {
            return x;
        }
        for (int i = pa.size() - 1; i >= 0; i--) {
            int px = pa[i][x], py = pa[i][y];
            if (px != py) {
                x = px;
                y = py;
            }
        }
        return pa[0][x];
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        LcaBinaryLifting g(edges, s);
        FenwickTree<int> f(n);
        vector<bool> ans;
        string op;
        int x, y;
        char c;
        for (auto& q : queries) {
            stringstream ss(q);
            ss >> op >> x;
            if (op[0] == 'u') {
                ss >> c;
                int val = (1 << (s[x] - 'a')) ^ (1 << (c - 'a'));
                s[x] = c;
                f.update(g.tin[x], val);
                f.update(g.tout[x] + 1, val);
            } else {
                ss >> y;
                int lca = g.get_lca(x, y);
                int res = g.path_xor_from_root[x] ^ g.path_xor_from_root[y] ^ f.pre(g.tin[x]) ^ f.pre(g.tin[y]) ^
                          (1 << (s[lca] - 'a'));
                ans.push_back((res & (res - 1)) == 0);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
