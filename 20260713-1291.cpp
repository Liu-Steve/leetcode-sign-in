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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans{1,      2,      3,      4,       5,       6,       7,        8,        9,
                        12,     23,     34,     45,      56,      67,      78,       89,       123,
                        234,    345,    456,    567,     678,     789,     1234,     2345,     3456,
                        4567,   5678,   6789,   12345,   23456,   34567,   45678,    56789,    123456,
                        234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        auto l = lower_bound(ans.begin(), ans.end(), low);
        auto r = upper_bound(ans.begin(), ans.end(), high);
        return vector<int>(l, r);
    }
};

int main() {
    io;
    return 0;
}