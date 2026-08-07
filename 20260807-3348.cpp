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
    string smallestNumber(string s, long long t) {
        long long tmp = t;
        for (int i = 9; i > 1; i--) {
            while (tmp % i == 0) {
                tmp /= i;
            }
        }
        if (tmp > 1) {
            return "-1";
        }
        int n = s.length();
        vector<long long> left_t(n + 1);
        left_t[0] = t;
        int i0 = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                i0 = i;
                break;
            }
            left_t[i + 1] = left_t[i] / gcd(left_t[i], s[i] - '0');
        }
        if (left_t[n] == 1) {
            return s;
        }
        for (int i = i0; i >= 0; i--) {
            while (++s[i] <= '9') {
                long long tt = left_t[i] / gcd(left_t[i], s[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tt % k) {
                        k--;
                    }
                    tt /= k;
                    s[j] = '0' + k;
                }
                if (tt == 1) {
                    return s;
                }
            }
        }
        string ans;
        for (int i = 9; i > 1; i--) {
            while (t % i == 0) {
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    io;
    return 0;
}