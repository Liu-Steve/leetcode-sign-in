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

using matrix = vector<vector<long long>>;

matrix mul(matrix& a, matrix& b) {
    int n = a.size(), m = b[0].size();
    matrix c = matrix(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            if (a[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix pow_mul(matrix a, int n, matrix& f1) {
    matrix res = f1;
    while (n) {
        if (n & 1) {
            res = mul(a, res);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        matrix m(k * 2, vector<long long>(k * 2));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++) {
                m[i][k + j] = 1;
            }
            for (int j = i + 1; j < k; j++) {
                m[k + i][j] = 1;
            }
        }

        matrix f1(k * 2, vector<long long>(1, 1));
        matrix fn = pow_mul(m, n - 1, f1);

        long long ans = 0;
        for (auto& row : fn) {
            ans += row[0];
        }
        return ans % MOD;
    }
};

int main() {
    io;
    return 0;
}