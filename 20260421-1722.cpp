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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> g(n);
        for (auto& e : allowedSwaps) {
            int i = e[0], j = e[1];
            g[i].push_back(j);
            g[j].push_back(i);
        }
        vector<int8_t> vis(n);
        unordered_map<int, int> diff;
        auto dfs = [&](auto&& dfs, int x) -> void {
            vis[x] = true;
            diff[source[x]]++;
            diff[target[x]]--;
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(dfs, y);
                }
            }
        };
        int ans = 0;
        for (int x = 0; x < n; x++) {
            if (!vis[x]) {
                diff.clear();
                dfs(dfs, x);
                for (auto& [_, c] : diff) {
                    ans += abs(c);
                }
            }
        }
        return ans / 2;
    }
};

int main() {
    io;
    return 0;
}