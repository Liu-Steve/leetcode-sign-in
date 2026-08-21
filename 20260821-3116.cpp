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
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<long long>> mod(n + 1);
        for (int i = 1; i < (1 << n); ++i) {
            long long g = 1;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    g *= coins[j] / __gcd(g, (long long)coins[j]);
                    cnt++;
                }
            }
            mod[cnt].push_back(g);
        }
        auto func = [&](long long lim) {
            long long ret = 0;
            for (int i = 1; i <= n; ++i) {
                for (long long g : mod[i]) {
                    ret += lim / g * ((i % 2) * 2 - 1);
                }
            }
            return ret;
        };
        long long l = 0;
        long long r = INT64_MAX / 2;
        while (l + 1 < r) {
            long long m = (l + r) / 2;
            if (func(m) >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};

int main() {
    io;
    return 0;
}