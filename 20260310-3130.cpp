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

inline int idx(int zero, int one, int start) {
    return (zero << 11) | (one << 1) | start;
}

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<int> mem(1 << 21, -1);
        function<int(int, int, int)> dfs = [&](int zero, int one, int start) -> int {
            if (zero == 0) {
                return start == 1 && one <= limit;
            } else if (one == 0) {
                return start == 0 && zero <= limit;
            }
            int h = idx(zero, one, start);
            if (mem[h] != -1) {
                return mem[h];
            }
            long long ret = 0;
            if (start == 0) {
                ret = dfs(zero - 1, one, 0) + dfs(zero - 1, one, 1);
                if (zero > limit) {
                    ret += MOD - dfs(zero - limit - 1, one, 1);
                }
            } else {
                ret = dfs(zero, one - 1, 0) + dfs(zero, one - 1, 1);
                if (one > limit) {
                    ret += MOD - dfs(zero, one - limit - 1, 0);
                }
            }
            mem[h] = ret % MOD;
            return mem[h];
        };
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}