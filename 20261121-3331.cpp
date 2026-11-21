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
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
        vector<int> fa(n);
        vector<int> anc(26, -1);
        auto dfs1 = [&](auto&& dfs1, int root) -> void {
            int h = anc[s[root] - 'a'];
            if (h == -1) {
                fa[root] = parent[root];
            } else {
                fa[root] = h;
            }
            anc[s[root] - 'a'] = root;
            for (int nxt : children[root]) {
                dfs1(dfs1, nxt);
            }
            anc[s[root] - 'a'] = h;
        };
        dfs1(dfs1, 0);
        vector<vector<int>> sub(n);
        for (int i = 1; i < n; ++i) {
            sub[fa[i]].push_back(i);
        }
        vector<int> ans(n);
        auto dfs2 = [&](auto&& dfs2, int root) -> int {
            int ret = 1;
            for (int nxt : sub[root]) {
                ret += dfs2(dfs2, nxt);
            }
            ans[root] = ret;
            return ret;
        };
        dfs2(dfs2, 0);
        return ans;
    }
};

int main() {
    io;
    return 0;
}
