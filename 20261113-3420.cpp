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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cnt = 0;
        int r_tree = 0;
        vector<pair<int, int>> q;
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];
            int size = 1;
            while (!q.empty() && x >= q.back().first) {
                auto [v, sz] = q.back();
                q.pop_back();
                size += sz;
                cnt += (long long)(x - v) * sz;
            }
            q.emplace_back(x, size);
            r_tree = min(r_tree, (int)q.size() - 1);
            while (cnt > k) {
                auto& [v, sz] = q[r_tree];
                cnt -= v - nums[r];
                r--;
                sz--;
                if (sz == 0) {
                    r_tree++;
                }
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}
