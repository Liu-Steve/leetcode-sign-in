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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> pos(n);
        iota(pos.begin(), pos.end(), 0);
        sort(pos.begin(), pos.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[pos[i + 1]] - nums[pos[i]] > limit) {
                vector<int> sub_pos(pos.begin() + start, pos.begin() + i + 1);
                sort(sub_pos.begin(), sub_pos.end());
                for (int j = 0; j < sub_pos.size(); j++) {
                    ans[sub_pos[j]] = nums[pos[start + j]];
                }
                start = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}