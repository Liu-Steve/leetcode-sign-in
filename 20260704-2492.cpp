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
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> score(n + 1, INT32_MAX);
        vector<vector<int>> nxt(n + 1);
        for (auto& r : roads) {
            nxt[r[0]].push_back(r[1]);
            nxt[r[1]].push_back(r[0]);
            score[r[0]] = min(score[r[0]], r[2]);
            score[r[1]] = min(score[r[1]], r[2]);
        }
        int ans = INT32_MAX;
        vector<bool> vis(n + 1);
        auto dfs = [&](auto&& dfs, int root) {
            if (vis[root]) {
                return;
            }
            vis[root] = true;
            ans = min(ans, score[root]);
            for (int ch : nxt[root]) {
                dfs(dfs, ch);
            }
        };
        dfs(dfs, 1);
        return ans;
    }
};

int main() {
    io;
    return 0;
}