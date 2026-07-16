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
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MX = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> cnt(MX);
        for (int num : nums) {
            cnt[num]++;
        }
        vector<long long> gcdPair(MX);
        for (int i = MX - 1; i > 0; --i) {
            long long c = 0;
            for (int j = i; j < MX; j += i) {
                c += cnt[j];
                gcdPair[i] -= gcdPair[j];
            }
            gcdPair[i] += c * (c - 1) / 2;
        }
        partial_sum(gcdPair.begin(), gcdPair.end(), gcdPair.begin());
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = upper_bound(gcdPair.begin(), gcdPair.end(), queries[i]) - gcdPair.begin();
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}