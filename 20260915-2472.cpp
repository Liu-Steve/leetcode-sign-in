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
    int maxPalindromes(string s, int k) {
        string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";
        vector<int> half_len(t.size() - 2);
        half_len[1] = 1;
        int box_m = 0, box_r = 0;
        for (int i = 2; i < half_len.size(); i++) {
            int hl = 1;
            if (i < box_r) {
                hl = min(box_r - i, half_len[box_m * 2 - i]);
            }
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }
            half_len[i] = hl;
        }
        auto is_palindrome = [&](int l, int r) -> bool {
            return half_len[l + r + 2] > r - l + 1;
        };
        int n = s.size();
        int ans = 0;
        for (int i = 0; i <= n - k;) {
            if (is_palindrome(i, i + k - 1)) {
                ans++;
                i += k;
            } else if (i < n - k && is_palindrome(i, i + k)) {
                ans++;
                i += k + 1;
            } else {
                i++;
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}