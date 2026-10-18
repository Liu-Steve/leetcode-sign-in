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
    long long qpow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 2);
        vector<int> next(n + 2);
        vector<int> size(n + 2);
        for (int i = 0; i < n + 2; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        long long fac = 1, prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            fac = fac * (i + 1) % MOD;
            int x = nums[i];
            size[x] = 1;
            int left = prev[x];
            if (size[left] > 0) {
                size[x] += size[left];
                int pl = prev[left];
                prev[x] = pl;
                next[pl] = x;
            }
            int right = next[x];
            if (size[right] > 0) {
                size[x] += size[right];
                int nr = next[right];
                prev[nr] = x;
                next[x] = nr;
            }
            prod = prod * size[x] % MOD;
        }
        return (fac * qpow(prod, MOD - 2) - 1 + MOD) % MOD;
    }
};

int main() {
    io;
    return 0;
}