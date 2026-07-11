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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> nxt(n);
        for (auto& e : edges) {
            nxt[e[0]].push_back(e[1]);
            nxt[e[1]].push_back(e[0]);
        }
        auto dfs = [&](auto&& dfs, int root, int cnt) -> pair<int, int> {
            vis[root] = true;
            int v = 1;
            int e = nxt[root].size();
            for (int ch : nxt[root]) {
                if (vis[ch]) {
                    continue;
                }
                auto [nv, ne] = dfs(dfs, ch, cnt);
                v += nv;
                e += ne;
            }
            return {v, e};
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            auto [v, e] = dfs(dfs, i, nxt[i].size());
            ans += (e == v * (v - 1));
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}