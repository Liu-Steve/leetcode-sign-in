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
    char processStr(string s, long long k) {
        long long len = 0;
        for (char& ch : s) {
            if (ch == '*') {
                if (len > 0) {
                    len--;
                } else {
                    ch = '.';
                }
            } else if (ch == '#') {
                len *= 2;
            } else if (ch != '%') {
                len++;
            }
        }
        if (k >= len) {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            char ch = s[i];
            if (ch == '*') {
                len++;
            } else if (ch == '.') {
                continue;
            } else if (ch == '#') {
                len /= 2;
                k %= len;
            } else if (ch == '%') {
                k = len - 1 - k;
            } else if (k == len - 1) {
                return ch;
            } else {
                len--;
            }
        }
        return '_';
    }
};

int main() {
    io;
    return 0;
}