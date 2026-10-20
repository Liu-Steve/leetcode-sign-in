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
    int minOperations(string s) {
        if (s.size() == 2 && s[0] > s[1]) {
            return -1;
        }
        char lst = 'a';
        bool r = false;
        for (char ch : s) {
            if (ch < lst) {
                r = true;
                break;
            }
            lst = ch;
        }
        if (r == false) {
            return 0;
        }
        int n = s.size();
        char max_e = *max_element(s.begin(), s.end());
        char min_e = *min_element(s.begin(), s.end());
        bool max_only = true;
        bool min_only = true;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == max_e) {
                max_only = false;
            }
            if (s[i] == min_e) {
                min_only = false;
            }
        }
        if (s[0] == max_e && max_only && s[n - 1] == min_e && min_only) {
            return 3;
        }
        if (s[0] == min_e || s[n - 1] == max_e) {
            return 1;
        }
        return 2;
    }
};

int main() {
    io;
    return 0;
}