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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<array<int, 10>> tree1(1), tree2(1);
        tree1[0].fill(-1);
        tree2[0].fill(-1);
        auto build = [&](vector<int>& arr, vector<array<int, 10>> &tree) {
            for (int num : arr) {
                stack<int> st;
                while (num) {
                    st.push(num % 10);
                    num /= 10;
                }
                int p = 0;
                while (!st.empty()) {
                    int ch = st.top();
                    st.pop();
                    if (tree[p][ch] != -1) {
                        p = tree[p][ch];
                        continue;
                    }
                    int np = tree.size();
                    tree.emplace_back();
                    tree[np].fill(-1);
                    tree[p][ch] = np;
                    p = np;
                }
            }
        };
        build(arr1, tree1);
        build(arr2, tree2);
        int ans = 0;
        int d = 0;
        auto dfs = [&](auto&& dfs, int p1, int p2) -> void {
            for (int i = 0; i < 10; ++i) {
                if (tree1[p1][i] != -1 && tree2[p2][i] != -1) {
                    d++;
                    ans = max(ans, d);
                    dfs(dfs, tree1[p1][i], tree2[p2][i]);
                    d--;
                }
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};

int main() {
    io;
    return 0;
}