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

//(a^b)%MOD
long long qpow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

//(a/b)%MOD
long long frac_mod(long long a, long long b) {
    long long ans = a % MOD;
    ans *= qpow(b, MOD - 2);
    ans = ans % MOD;
    return ans;
}

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pre_x(n + 1);
        vector<long long> pre_10(n + 1);
        vector<int> pre_sum(n + 1);
        pre_10[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                pre_x[i + 1] = pre_x[i];
                pre_10[i + 1] = pre_10[i];
                pre_sum[i + 1] = pre_sum[i];
                continue;
            }
            pre_x[i + 1] = (pre_x[i] * 10 + s[i] - '0') % MOD;
            pre_10[i + 1] = pre_10[i] * 10 % MOD;
            pre_sum[i + 1] = pre_sum[i] + s[i] - '0';
        }
        vector<int> ans;
        for (auto& q : queries) {
            long long x = (pre_x[q[1] + 1] - pre_x[q[0]] * frac_mod(pre_10[q[1] + 1], pre_10[q[0]]) % MOD + MOD) % MOD;
            ans.push_back(x * (pre_sum[q[1] + 1] - pre_sum[q[0]]) % MOD);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}