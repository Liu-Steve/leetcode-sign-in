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
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        unordered_map<int, pair<int, int>> mem;
        auto dfs = [&](auto&& dfs, int idx, int m) -> pair<int, int> {
            if (idx >= n) {
                return {0, 0};
            }
            int key = ((idx << 16) | m);
            if (mem.count(key)) {
                return mem[key];
            }
            int a = 0;
            int b = 0;
            int sum = 0;
            for (int i = idx; i < n && i - idx + 1 <= 2 * m; ++i) {
                sum += piles[i];
                auto [nb, na] = dfs(dfs, i + 1, max(m, i - idx + 1));
                if (sum + na > a) {
                    a = sum + na;
                    b = nb;
                }
            }
            return mem[key] = {a, b};
        };
        auto [a, b] = dfs(dfs, 0, 1);
        return a;
    }
};

int main() {
    io;
    return 0;
}