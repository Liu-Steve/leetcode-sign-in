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
    int maximumLength(vector<int>& nums) {
        map<long long, int> cnt;
        unordered_set<long long> vis;
        for (int num : nums) {
            cnt[num]++;
        }
        int ans = 0;
        for (auto [k, v] : cnt) {
            if (vis.count(k)) {
                continue;
            }
            vis.insert(k);
            if (k == 1) {
                ans = max(ans, (cnt[k] - 1) / 2 + 1);
                continue;
            }
            int len = 1;
            long long mul = k;
            while (cnt[mul] >= 2) {
                if (!cnt.count(mul * mul)) {
                    break;
                }
                len++;
                mul *= mul;
                vis.insert(mul);
            }
            ans = max(ans, len);
        }
        return ans * 2 - 1;
    }
};

int main() {
    io;
    return 0;
}