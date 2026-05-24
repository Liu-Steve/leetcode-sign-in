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
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st1;
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
            while (!st1.empty() && arr[st1.top()] <= x) {
                st1.pop();
            }
            if (st1.empty() || i - st1.top() > d) {
                left[i] = -1;
            } else {
                left[i] = st1.top();
            }
            st1.push(i);
        }
        vector<int> right(n);
        stack<int> st2;
        for (int i = n - 1; i >= 0; --i) {
            int x = arr[i];
            while (!st2.empty() && arr[st2.top()] <= x) {
                st2.pop();
            }
            if (st2.empty() || st2.top() - i > d) {
                right[i] = -1;
            } else {
                right[i] = st2.top();
            }
            st2.push(i);
        }
        vector<int> mem(n);
        auto dfs = [&](auto&& dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            int ret = mem[i];
            if (ret == 0) {
                ret = max(dfs(dfs, left[i]), dfs(dfs, right[i])) + 1;
            }
            mem[i] = ret;
            return ret;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(dfs, i));
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}