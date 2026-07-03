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
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> nxt(n);
        for (vector<int>& e : edges) {
            if (!online[e[0]] || !online[e[1]]) {
                continue;
            }
            nxt[e[0]].emplace_back(e[1], e[2]);
        }
        auto dij = [&](int lim) -> bool {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.emplace(0, 0);
            vector<bool> vis(n);
            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();
                if (vis[node]) {
                    continue;
                }
                vis[node] = true;
                if (node == n - 1) {
                    return d <= k;
                }
                for (auto [ch, len] : nxt[node]) {
                    if (len >= lim && !vis[ch]) {
                        pq.emplace(d + len, ch);
                    }
                }
            }
            return false;
        };
        if (!dij(0)) {
            return -1;
        }
        int l = 0;
        int r = INT32_MAX;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (dij(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};

int main() {
    io;
    return 0;
}