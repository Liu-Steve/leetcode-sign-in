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

struct Data {
    int mx, pre, suf;
};

class SegmentTree {
    int n;
    string s;
    vector<Data> tree;

    void maintain(int node, int l, int m, int r) {
        Data& left = tree[node * 2];
        Data& right = tree[node * 2 + 1];
        int mx = max(left.mx, right.mx);
        int pre = left.pre;
        int suf = right.suf;
        if (s[m] == s[m + 1]) {
            mx = max(mx, left.suf + right.pre);
            if (left.pre == m - l + 1) {
                pre += right.pre;
            }
            if (right.suf == r - m) {
                suf += left.suf;
            }
        }
        tree[node] = {mx, pre, suf};
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1};
            return;
        }
        int m = (l + r) >> 1;
        build(node * 2, l, m);
        build(node * 2 + 1, m + 1, r);
        maintain(node, l, m, r);
    }

    void update(int node, int l, int r, int i, char val) {
        if (l == r) {
            s[i] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            update(node * 2, l, m, i, val);
        } else {
            update(node * 2 + 1, m + 1, r, i, val);
        }
        maintain(node, l, m, r);
    }

public:
    SegmentTree(const string& s) : n(s.size()), s(s), tree(2 << __bit_width(s.size() - 1)) {
        build(1, 0, n - 1);
    }

    void update(int i, char val) {
        update(1, 0, n - 1, i, val);
    }

    int query_all() const {
        return tree[1].mx;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree t(s);
        int q = queryIndices.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            t.update(queryIndices[i], queryCharacters[i]);
            ans[i] = t.query_all();
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}