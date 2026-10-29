#include <bits/stdc++.h>

#include <queue>
#include <unordered_map>
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
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> nxt(n);
        for (auto& e : edges) {
            nxt[e[0]].emplace_back(e[1], e[2]);
        }
        typedef struct st {
            int id;
            int rep;
            long long len;
            bool operator<(const st& other) const {
                if (this->len == other.len) {
                    return this->rep > other.rep;
                }
                return this->len > other.len;
            }
            st(int id, int rep, long long len) : id(id), rep(rep), len(len) {}
        } State;
        priority_queue<State> pq;
        pq.emplace(0, 1, 0);
        vector<int> last(n, k + 1);
        while (!pq.empty()) {
            State now = pq.top();
            pq.pop();
            if (now.id == n - 1) {
                return now.len;
            }
            if (now.rep >= last[now.id]) {
                continue;
            }
            last[now.id] = now.rep;
            for (auto [child, w] : nxt[now.id]) {
                if (labels[now.id] == labels[child]) {
                    if (now.rep == k) {
                        continue;
                    }
                    pq.emplace(child, now.rep + 1, now.len + w);
                } else {
                    pq.emplace(child, 1, now.len + w);
                }
            }
        }
        return -1;
    }
};

int main() {
    io;
    return 0;
}
