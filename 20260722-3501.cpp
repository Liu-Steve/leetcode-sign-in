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

struct Pair {
    int l, r;
};

class SparseTable {
    vector<vector<int>> st;

public:
    SparseTable(vector<Pair>& a) {
        int n = a.size() - 1;
        int w = __bit_width(unsigned(n));
        st.resize(w, vector<int>(n));
        for (int j = 0; j < n; j++) {
            st[0][j] = a[j].r - a[j].l + a[j + 1].r - a[j + 1].l;
        }
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l >= r) {
            return 0;
        }
        int k = __bit_width(unsigned(r - l)) - 1;
        return max(st[k][l], st[k][r - (1 << k)]);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int total1 = 0;
        vector<Pair> a = {{-1, -1}};
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                if (s[i] == '1') {
                    total1 += i - start + 1;
                } else {
                    a.emplace_back(start, i + 1);
                }
                start = i + 1;
            }
        }
        a.emplace_back(n + 1, n + 1);
        auto merge = [](int x, int y) {
            return x > 0 && y > 0 ? x + y : 0;
        };
        SparseTable st(a);
        vector<int> ans(queries.size());
        for (int qi = 0; qi < queries.size(); qi++) {
            int ql = queries[qi][0], qr = queries[qi][1] + 1;
            int i = lower_bound(a.begin(), a.end(), ql,
                                [&](const Pair& p, int val) {
                                    return p.l < val;
                                }) -
                    a.begin();
            int j = upper_bound(a.begin(), a.end(), qr,
                                [&](int val, const Pair& p) {
                                    return val < p.r;
                                }) -
                    a.begin() - 1;
            int mx = 0;
            if (i <= j) {
                mx = max({
                    st.query(i, j),
                    merge(a[i - 1].r - ql, a[i].r - a[i].l),
                    merge(qr - a[j + 1].l, a[j].r - a[j].l),
                });
            } else if (i == j + 1) {
                mx = merge(a[i - 1].r - ql, qr - a[j + 1].l);
            }
            ans[qi] = total1 + mx;
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}