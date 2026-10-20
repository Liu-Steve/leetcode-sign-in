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
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                fac.push_back(i);
                if (i * i < n) {
                    fac.push_back(n / i);
                }
            }
        }
        int ans = 0;
        for (int k : fac) {
            bool valid = true;
            int lst = 0;
            int l = 0;
            for (int r = k; r <= n; l += k, r += k) {
                int bottom = *min_element(nums.begin() + l, nums.begin() + r);
                if (bottom < lst) {
                    valid = false;
                    break;
                }
                lst = *max_element(nums.begin() + l, nums.begin() + r);
                int q = 0;
                int cnt = 0;
                if (nums[l] < nums[r - 1]) {
                    cnt++;
                }
                for (int i = l; i < r; ++i) {
                    if (nums[i] < q) {
                        cnt++;
                    }
                    q = nums[i];
                }
                if (cnt > 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans += k;
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}