#include <vector>

#include "bits/stdc++.h"
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
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed,
                          vector<int> &cost) {
        const int INF = 0x3f3f3f3f;
        vector g(26, vector(26, INF));
        for (int i = 0; i < cost.size(); ++i) {
            g[original[i] - 'a'][changed[i] - 'a'] = min(g[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int i = 0; i < 26; ++i) {
            g[i][i] = 0;
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (g[source[i] - 'a'][target[i] - 'a'] == INF) {
                return -1;
            }
            ans += g[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}