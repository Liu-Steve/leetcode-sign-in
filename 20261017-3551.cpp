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
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> ref(nums.begin(), nums.end());
        sort(ref.begin(), ref.end(), [&](int num1, int num2) {
            int cnt1 = 0;
            for (int p = num1; p > 0; p /= 10) {
                cnt1 += p % 10;
            }
            int cnt2 = 0;
            for (int p = num2; p > 0; p /= 10) {
                cnt2 += p % 10;
            }
            if (cnt1 != cnt2) {
                return cnt1 < cnt2;
            }
            return num1 < num2;
        });
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[ref[i]] = i;
        }
        vector<int> to(n);
        for (int i = 0; i < n; ++i) {
            to[i] = mp[nums[i]];
        }
        vector<bool> vis(n);
        int cnt = 0;
        auto dfs = [&](auto&& dfs, int i) {
            if (vis[i]) {
                return;
            }
            vis[i] = true;
            dfs(dfs, to[i]);
        };
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            cnt++;
            dfs(dfs, i);
        }
        return n - cnt;
    }
};

int main() {
    io;
    return 0;
}