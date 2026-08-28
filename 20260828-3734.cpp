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
    string lexGreaterPermutation(vector<int>& left, string target) {
        int n = target.size();
        for (int i = 0; i < n; i++) {
            left[target[i] - 'a']--;
        }
        for (int i = n - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            left[b]++;
            bool ok = true;
            for (int c : left) {
                if (c < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = b + 1; j < 26; j++) {
                if (left[j] == 0) {
                    continue;
                }

                left[j]--;
                target[i] = 'a' + j;
                target.resize(i + 1);

                for (int k = 0; k < 26; k++) {
                    target += string(left[k], 'a' + k);
                }
                return target;
            }
        }
        return "";
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        int sig = 0;
        int mid = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                sig++;
                mid = i;
            }
        }
        if (sig > 1) {
            return "";
        }
        int n = target.size();
        string mirror = target;
        vector<int> m_cnt(26);
        for (int i = 0; i < n - 1 - i; ++i) {
            mirror[n - 1 - i] = mirror[i];
        }
        if (sig == 1) {
            mirror[n / 2] = 'a' + mid;
        }
        for (char ch : mirror) {
            m_cnt[ch - 'a']++;
        }
        if (mirror > target && cnt == m_cnt) {
            return mirror;
        }
        if (sig == 1) {
            cnt[mid]--;
        }
        for (int& num : cnt) {
            num /= 2;
        }
        string ret = lexGreaterPermutation(cnt, target.substr(0, n / 2));
        if (ret == "") {
            return "";
        }
        string ans = ret;
        if (sig == 1) {
            ans.push_back('a' + mid);
        }
        reverse(ret.begin(), ret.end());
        ans += ret;
        return ans;
    }
};

int main() {
    io;
    return 0;
}