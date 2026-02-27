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
    int minOperations(string s, int k) {
        int n = s.size();
        int z = 0;
        for (char ch : s) {
            if (ch == '0') {
                z++;
            }
        }
        if (z == 0) {
            return 0;
        }
        if (k == n) {
            return z == n ? 1 : -1;
        }
        int ans = INT_MAX;
        if (z % 2 == 0) {
            int m = max((z + k - 1) / k, (z + n - k - 1) / (n - k));
            ans = m + m % 2;
        }
        if (z % 2 == k % 2) {
            int m = max((z + k - 1) / k, (n - z + n - k - 1) / (n - k));
            ans = min(ans, m | 1);
        }
        return ans < INT_MAX ? ans : -1;
    }
};

int main() {
    io;
    Solution s;
    return 0;
}