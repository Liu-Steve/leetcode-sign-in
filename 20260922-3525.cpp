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

class SegmentTree {
    using T = pair<int, array<int, 5>>;

    int k;
    int n;
    vector<T> tree;

    T merge_val(T a, T b) const {
        auto [left_mul, cnt] = a;
        for (int rx = 0; rx < k; rx++) {
            cnt[left_mul * rx % k] += b.second[rx];
        }
        return {left_mul * b.first % k, cnt};
    }

    T new_val(int val) const {
        int mul = val % k;
        array<int, 5> cnt{};
        cnt[mul] = 1;
        return {mul, cnt};
    }

    void maintain(int node) {
        tree[node] = merge_val(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(const vector<int>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = new_val(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(a, node * 2, l, m);
        build(a, node * 2 + 1, m + 1, r);
        maintain(node);
    }

    void update(int node, int l, int r, int i, int val) {
        if (l == r) {
            tree[node] = new_val(val);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            update(node * 2, l, m, i, val);
        } else {
            update(node * 2 + 1, m + 1, r, i, val);
        }
        maintain(node);
    }

    T query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int m = (l + r) / 2;
        if (qr <= m) {
            return query(node * 2, l, m, ql, qr);
        }
        if (ql > m) {
            return query(node * 2 + 1, m + 1, r, ql, qr);
        }
        T l_res = query(node * 2, l, m, ql, qr);
        T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge_val(l_res, r_res);
    }

public:
    SegmentTree(const vector<int>& a, int k) : k(k), n(a.size()), tree(2 << __bit_width(a.size() - 1)) {
        build(a, 1, 0, n - 1);
    }

    void update(int i, int val) {
        update(1, 0, n - 1, i, val);
    }

    T query(int ql, int qr) const {
        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree t(nums, k);
        int n = nums.size();
        vector<int> ans;
        for (auto& q : queries) {
            t.update(q[0], q[1]);
            auto [_, cnt] = t.query(q[2], n - 1);
            ans.push_back(cnt[q[3]]);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}