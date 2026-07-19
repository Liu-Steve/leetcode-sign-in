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
    string smallestSubsequence(string s) {
        vector<int> lst(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            lst[s[i] - 'a'] = max(i, lst[s[i] - 'a']);
        }
        string ans;
        vector<int> vis(26);
        for (int i = 0; i < n; ++i) {
            if (vis[s[i] - 'a'] != 0) {
                if (i == lst[s[i] - 'a']) {
                    vis[s[i] - 'a'] = 2;
                }
                continue;
            }
            while (!ans.empty() && ans.back() >= s[i]) {
                if (vis[ans.back() - 'a'] != 2) {
                    vis[ans.back() - 'a'] = 0;
                    ans.pop_back();
                } else {
                    break;
                }
            }
            if (i == lst[s[i] - 'a']) {
                vis[s[i] - 'a'] = 2;
            } else {
                vis[s[i] - 'a'] = 1;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}