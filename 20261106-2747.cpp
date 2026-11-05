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
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> events;
        for (auto& e : logs) {
            events.push_back({e[1], 0, e[0]});
        }
        int q = queries.size();
        unordered_map<int, vector<int>> q2idx;
        for (int i = 0; i < q; ++i) {
            if (!q2idx.count(queries[i])) {
                events.push_back({queries[i], 1});
            }
            q2idx[queries[i]].push_back(i);
        }
        sort(events.begin(), events.end());
        vector<int> servers(n + 1);
        int cnt = n;
        vector<int> ans(q);
        int p = 0;
        for (auto& e : events) {
            if (e[1] == 0) {
                servers[e[2]]++;
                if (servers[e[2]] == 1) {
                    cnt--;
                }
            } else {
                while (events[p][0] < e[0] - x) {
                    if (events[p][1] == 0) {
                        servers[events[p][2]]--;
                        if (servers[events[p][2]] == 0) {
                            cnt++;
                        }
                    }
                    p++;
                }
                for (int idx : q2idx[e[0]]) {
                    ans[idx] = cnt;
                }
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
