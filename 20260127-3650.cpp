#include <bits/stdc++.h>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int minCost(int n, vector<vector<int>> &edges) {
        vector<unordered_map<int, int>> mp(n);
        for (auto &e : edges) {
            if (mp[e[0]].count(e[1]) == 0) {
                mp[e[0]][e[1]] = e[2];
            } else {
                mp[e[0]][e[1]] = min(mp[e[0]][e[1]], e[2]);
            }
            if (mp[e[1]].count(e[0]) == 0) {
                mp[e[1]][e[0]] = e[2] * 2;
            } else {
                mp[e[1]][e[0]] = min(mp[e[1]][e[0]], e[2] * 2);
            }
        }
        vector<int> vis(n, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (vis[node] != INT32_MAX) {
                continue;
            }
            vis[node] = dis;
            if (node == n - 1) {
                break;
            }
            for (auto it : mp[node]) {
                pq.emplace(dis + it.second, it.first);
            }
        }
        if (vis[n - 1] == INT32_MAX) {
            return -1;
        }
        return vis[n - 1];
    }
};

int main() {
    io;
    Solution s;
    return 0;
}