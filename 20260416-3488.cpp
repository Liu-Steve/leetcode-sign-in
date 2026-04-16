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
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> lst;
        vector<int> dis(n, INT32_MAX);
        for (int i = 0; i < n; ++i) {
            if (lst.count(nums[i])) {
                int d = i - lst[nums[i]];
                dis[i] = min(dis[i], d);
                dis[lst[nums[i]]] = min(dis[lst[nums[i]]], d);
            }
            lst[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (lst[nums[i]] != i) {
                int d = i + n - lst[nums[i]];
                dis[i] = min(dis[i], d);
                dis[lst[nums[i]]] = min(dis[lst[nums[i]]], d);
            }
            lst[nums[i]] = i;
        }
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(dis[q] == INT32_MAX ? -1 : dis[q]);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}