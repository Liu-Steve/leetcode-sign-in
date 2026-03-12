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

class DSet {
private:
    vector<int> fa;
    int n;
    int findFa(int node) {
        while (fa[node] >= 0) {
            node = fa[node];
        }
        return node;
    }

public:
    DSet(int n) : fa(n, -1) {}

    bool add(int n1, int n2) {
        int fa1 = findFa(n1);
        int fa2 = findFa(n2);
        if (fa1 == fa2) {
            return false;
        }
        if (fa[fa1] > fa[fa2]) {
            fa[fa2] += fa[fa1];
            fa[fa1] = fa2;
        } else {
            fa[fa1] += fa[fa2];
            fa[fa2] = fa1;
        }
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [&](const vector<int>& e1, const vector<int>& e2) {
            if (e1[3] != e2[3]) {
                return e1[3] > e2[3];
            } else {
                return e1[2] > e2[2];
            }
        });
        if (edges.size() < n - 1) {
            return -1;
        }
        int cnt = 0;
        int ans = INT32_MAX;
        DSet s(n);
        for (auto& e : edges) {
            if (e[3] == 1) {
                bool ret = s.add(e[0], e[1]);
                if (!ret) {
                    return -1;
                }
                ans = min(ans, e[2]);
                cnt++;
                continue;
            }
            if (cnt >= n - 1) {
                break;
            }
            bool ret = s.add(e[0], e[1]);
            if (!ret) {
                continue;
            }
            if (cnt >= n - 1 - k) {
                ans = min(ans, e[2] * 2);
            } else {
                ans = min(ans, e[2]);
            }
            cnt++;
        }
        if (cnt != n - 1) {
            return -1;
        }
        return ans;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}