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
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> idx;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                idx.push_back(i);
            }
        }
        if (idx.size() < k) {
            return "";
        }
        string ans = s.substr(idx[0], idx[k - 1] - idx[0] + 1);
        for (int i = 1; i + k - 1 < idx.size(); ++i) {
            string tmp = s.substr(idx[i], idx[i + k - 1] - idx[i] + 1);
            if (tmp.size() < ans.size()) {
                ans = tmp;
            } else if (tmp.size() == ans.size()) {
                ans = min(ans, tmp);
            }
        }
        return ans;
    }
};

int main() {
    io;
    return 0;
}