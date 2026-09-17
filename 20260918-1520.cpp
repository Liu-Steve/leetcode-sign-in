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
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> pos[26];
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        vector<int> g[26];
        for (int i = 0; i < 26; i++) {
            if (pos[i].empty()) {
                continue;
            }
            int l = pos[i][0], r = pos[i].back();
            for (int j = 0; j < 26; j++) {
                if (j == i) {
                    continue;
                }
                auto& q = pos[j];
                int k = lower_bound(q.begin(), q.end(), l) - q.begin();
                if (k < q.size() && q[k] <= r) {
                    g[i].push_back(j);
                }
            }
        }
        vector<bool> vis(26);
        int l, r;
        auto dfs = [&](auto&& dfs, int x) -> void {
            vis[x] = true;
            l = min(l, pos[x][0]);
            r = max(r, pos[x].back());
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(dfs, y);
                }
            }
        };
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (pos[i].empty()) {
                continue;
            }
            fill(vis.begin(), vis.end(), false);
            l = INT_MAX;
            r = 0;
            dfs(dfs, i);
            intervals.emplace_back(l, r);
        }
        vector<string> ans;
        sort(intervals.begin(), intervals.end(), [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second < p2.second;
        });
        int pre_r = -1;
        for (auto& [l, r] : intervals) {
            if (l > pre_r) {
                ans.push_back(s.substr(l, r - l + 1));
                pre_r = r;
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}