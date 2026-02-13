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
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int start = i;
            for (i++; i < n && s[i] == s[i - 1]; i++);
            ans = max(ans, i - start);
        }
        auto f = [&](char x, char y) -> void {
            for (int i = 0; i < n; i++) {
                unordered_map<int, int> pos = {{0, i - 1}};
                int d = 0;
                for (; i < n && (s[i] == x || s[i] == y); i++) {
                    d += s[i] == x ? 1 : -1;
                    if (pos.count(d)) {
                        ans = max(ans, i - pos[d]);
                    } else {
                        pos[d] = i;
                    }
                }
            }
        };
        unordered_map<long long, int> pos = {{1LL * n << 32 | n, -1}};
        f('a', 'b');
        f('a', 'c');
        f('b', 'c');
        int cnt[3]{};
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            long long p = 1LL * (cnt[0] - cnt[1] + n) << 32 | (cnt[1] - cnt[2] + n);
            if (pos.count(p)) {
                ans = max(ans, i - pos[p]);
            } else {
                pos[p] = i;
            }
        }
        return ans;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}