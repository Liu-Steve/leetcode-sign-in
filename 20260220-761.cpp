#include <bits/stdc++.h>
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
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }
        int d = 0;
        int start = 0;
        vector<string> sub;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                d--;
            } else {
                d++;
            }
            if (d == 0) {
                sub.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }
        sort(sub.begin(), sub.end(), greater<string>());
        stringstream ss;
        for (string& str : sub) {
            ss << str;
        }
        return ss.str();
    }
};

int main() {
    io;
    Solution s;
    return 0;
}