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
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;
        vector<int> total(26);
        for (int i = 0; i < m; i++) {
            total[s[i] - 'a']++;
        }
        vector<int> cnt(26);
        long long perm = 1;
        int i = m - 1, j = 25;
        for (; i >= 0 && perm < k; i--) {
            while (cnt[j] == total[j]) {
                j--;
            }
            cnt[j]++;
            perm = perm * (m - i) / cnt[j];
        }
        if (perm < k) {
            return "";
        }
        string left_s;
        for (int ch = 0; ch <= j; ch++) {
            left_s += string(total[ch] - cnt[ch], 'a' + ch);
        }
        int j0 = j;
        for (i++; i < m; i++) {
            for (int j = j0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }
                long long p = perm * cnt[j] / (m - i);
                if (p >= k) {
                    left_s += 'a' + j;
                    cnt[j]--;
                    perm = p;
                    break;
                }
                k -= p;
            }
        }
        string ans = left_s;
        if (n % 2) {
            ans += s[n / 2];
        }
        reverse(left_s.begin(), left_s.end());
        return ans + left_s;
    }
};

int main() {
    io;
    return 0;
}