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
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        vector<int> f0(k, 1);
        vector<int> f1(k, 1);
        for (int i = 2; i <= n; i++) {
            long long pre = 0;
            for (int j = 0; j < k; j++) {
                int v = f1[j];
                f1[j] = pre % MOD;
                pre += v;
            }
            long long suf = 0;
            for (int j = k - 1; j >= 0; j--) {
                int v = f0[j];
                f0[j] = suf % MOD;
                suf += v;
            }
            swap(f0, f1);
        }
        long long res0 = reduce(f0.begin(), f0.end(), 0LL);
        long long res1 = reduce(f1.begin(), f1.end(), 0LL);
        return (res0 + res1) % MOD;
    }
};

int main() {
    io;
    return 0;
}