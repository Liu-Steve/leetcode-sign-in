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
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m = restrictions.size();
        if (m == 0) {
            return n - 1;
        }
        sort(restrictions.begin(), restrictions.end());
        vector<int> h(m);
        h[0] = min(restrictions[0][0] - 1, restrictions[0][1]);
        for (int i = 1; i < m; i++) {
            h[i] = min(h[i - 1] + restrictions[i][0] - restrictions[i - 1][0], restrictions[i][1]);
        }
        for (int i = m - 2; i >= 0; i--) {
            h[i] = min(h[i], h[i + 1] + restrictions[i + 1][0] - restrictions[i][0]);
        }
        int ans = max((restrictions[0][0] - 1 + h[0]) / 2, h[m - 1] + n - restrictions[m - 1][0]);
        for (int i = 0; i < m - 1; i++) {
            ans = max(ans, (restrictions[i + 1][0] - restrictions[i][0] + h[i] + h[i + 1]) / 2);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}